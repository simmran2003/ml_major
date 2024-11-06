import os, sys
from io import BytesIO, IOBase
from array import array
from itertools import accumulate
import bisect
import math
from collections import deque

# from functools import cache
# cache cf需要自己提交 pypy3.9!
from copy import deepcopy


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, 8192))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().strip()
ints = lambda: list(map(int, input().split()))
Int = lambda: int(input())


def queryInteractive(a, b, c):
    print('? {} {} {}'.format(a, b, c))
    sys.stdout.flush()
    return int(input())


def answerInteractive(x1, x2):
    print('! {} {}'.format(x1, x2))
    sys.stdout.flush()


INF = 1000000000



from types import GeneratorType


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc

class LCA:
    """<O(n), O(log(n))>"""

    def __init__(self, G, root, parents):
        from collections import deque

        self.n = len(G)
        self.tour = [0] * (2 * self.n - 1)
        self.depth_list = [0] * (2 * self.n - 1)
        self.id = [-1] * self.n
        self.dfs(G, root, parents)
        self._rmq_init(self.depth_list)

    def _rmq_init(self, arr):
        n = self.mod = len(arr)
        self.seg_len = 1 << (n - 1).bit_length()
        self.seg = [self.n * n] * (2 * self.seg_len)
        seg = self.seg
        for i, e in enumerate(arr):
            seg[self.seg_len + i] = n * e + i
        for i in range(self.seg_len - 1, 0, -1):
            seg[i] = min(seg[2 * i], seg[2 * i + 1])

    def _rmq_query(self, l, r):
        l += self.seg_len
        r += self.seg_len
        res = self.n * self.mod
        seg = self.seg
        while l < r:
            if r & 1:
                r -= 1
                res = min(res, seg[r])
            if l & 1:
                res = min(res, seg[l])
                l += 1
            l >>= 1
            r >>= 1
        return res % self.mod

    def dfs(self, G, root, parents):
        id = self.id
        tour = self.tour
        depth_list = self.depth_list
        v = root
        it = [0] * self.n
        visit_id = 0
        depth = 0
        while v != -1:
            if id[v] == -1:
                id[v] = visit_id
            tour[visit_id] = v
            depth_list[visit_id] = depth
            visit_id += 1
            g = G[v]
            if it[v] == len(g):
                v = parents[v]
                depth -= 1
                continue
            if g[it[v]] == parents[v]:
                it[v] += 1
                if it[v] == len(g):
                    v = parents[v]
                    depth -= 1
                    continue
                else:
                    child = g[it[v]]
                    it[v] += 1
                    v = child
                    depth += 1
            else:
                child = g[it[v]]
                it[v] += 1
                v = child
                depth += 1

    def lca(self, u: int, v: int) -> int:
        l, r = self.id[u], self.id[v]
        if r < l:
            l, r = r, l
        q = self._rmq_query(l, r + 1)
        return self.tour[q]

    def dist(self, u: int, v: int) -> int:
        lca = self.lca(u, v)
        depth_u = self.depth_list[self.id[u]]
        depth_v = self.depth_list[self.id[v]]
        depth_lca = self.depth_list[self.id[lca]]
        return depth_u + depth_v - 2 * depth_lca

class Graph:
    def __init__(self, n):
        self.n = n
        self.dis = [INF] * n
        self.g = [[] for _ in range(n)]
        self.root_dis = [INF] * n
        self.lca_nodes = []
        self.first_occur = [0] * n
        self.MAX_LOG = 18
        self.rmq = [array('l',[INF]*(2*n)) for _ in range(self.MAX_LOG)]
    def input(self):
        for _ in range(self.n-1):
            u, v = map(int, input().split())
            u -= 1
            v -= 1
            self.g[u].append(v)
            self.g[v].append(u)
        self.update_distance([0])
        self.root_dis[0] = 0
        self.dfs_plus(0)
        # print(len(self.lca_nodes), self.lca_nodes)
        for j in range(self.MAX_LOG):
            step = 2**(j-1)
            length = len(self.lca_nodes)
            for i in range(length):
                u = self.lca_nodes[i]
                if j == 0:
                    self.rmq[j][i] = self.root_dis[u]
                else:
                    self.rmq[j][i] = self.rmq[j-1][i]
                    if i + step < length:
                        self.rmq[j][i] = min(self.rmq[j][i], self.rmq[j-1][i+step])
    def dfs_plus(self, start):
        Q = deque([(start,0,-1)])
        while Q:
            u, nxt, last = Q.pop()
            if nxt == 0:
                self.first_occur[u] = len(self.lca_nodes)
                self.lca_nodes.append(u)
            is_add_back = False
            for i in range(nxt, len(self.g[u])):
                v = self.g[u][i]
                if v != last:
                    self.root_dis[v] = self.root_dis[u] + 1
                    Q.append((u, i+1, last))
                    Q.append((v, 0, u))
                    is_add_back = True
                    break
            if last != -1 and not is_add_back:
                self.lca_nodes.append(last)
    def dfs(self, u, last):
        self.first_occur[u] = len(self.lca_nodes)
        self.lca_nodes.append(u)
        for v in self.g[u]:
            if v != last:
                self.root_dis[v] = self.root_dis[u] + 1
                self.dfs(v,u)
                self.lca_nodes.append(u)
    def update_distance(self, l):
        # nodes in l are changed to distance 0, update others
        for u in l:
            self.dis[u] = 0
        Q = deque(l)
        while Q:
            u = Q.popleft()
            for v in self.g[u]:
                if self.dis[v] > self.dis[u] + 1:
                    self.dis[v] = self.dis[u] + 1
                    Q.append(v)
    def get_distance(self, u):
        return self.dis[u]
    def get_pair_distance(self, u, v):
        return self.root_dis[u] + self.root_dis[v] \
            - 2 * self.get_lca_root_distance(u,v)
    def get_lca_root_distance(self, u, v):
        fu, fv = self.first_occur[u], self.first_occur[v]
        if fu > fv:
            fu, fv = fv, fu
        length = fv - fu + 1
        j, step = 0, 1
        while step*2 < length:
            j += 1
            step <<= 1
        return min(self.rmq[j][fu], self.rmq[j][fv - step + 1])


n,m = ints()
g = Graph(n)
g.input()


LIM = int(math.sqrt(m))
buck = [0]

def qry(x):
    ans = g.dis[x]
    for y in buck:
        ans = min(ans,g.get_pair_distance(y,x))
    return ans




for i in range(m):
    t,v = ints()
    v -= 1
    if t == 1:
        buck.append(v)
    else:
        print(qry(v))
        
    if len(buck) >= LIM:
        g.update_distance(buck)
        buck = []
