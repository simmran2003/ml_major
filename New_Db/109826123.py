class CentroidDecomposition():
    def __init__(self, g):
        self.g = g
        self.n = len(g)

        self.parent = [-1]*self.n
        self.size = [1]*self.n
        self.cdparent = [-1]*self.n
        self.cddepth = [0]*self.n
        self.cdorder = [-1]*self.n
        self.cdused = [0]*self.n

        cnt = 0
        stack = [0]
        while stack:
            v = stack.pop()
            p = self.cdparent[v]
            c = self.get_centroid(v)
            self.cdused[c] = True
            self.cdparent[c] = p
            self.cddepth[c] = self.cddepth[v]
            self.cdorder[c] = cnt
            cnt += 1
            for u in self.g[c]:
                if self.cdused[u]:
                    continue
                self.cdparent[u] = c
                self.cddepth[u] = self.cddepth[c]+1
                stack.append(u)

    def get_centroid(self, root):
        self.parent[root] = -1
        self.size[root] = 1
        stack = [root]
        order = []
        while stack:
            v = stack.pop()
            order.append(v)
            for u in g[v]:
                if self.parent[v] == u or self.cdused[u]:
                    continue
                self.size[u] = 1
                self.parent[u] = v
                stack.append(u)
        if len(order) <= 2:
            return root
        for v in reversed(order):
            if self.parent[v] == -1:
                continue
            self.size[self.parent[v]] += self.size[v]
        total = self.size[root]
        v = root
        while True:
            for u in self.g[v]:
                if self.parent[v] == u or self.cdused[u]:
                    continue
                if self.size[u] > total//2:
                    v = u
                    break
            else:
                return v

class SegTree:
    def __init__(self, init_val, ide_ele, segfunc):
        self.n = len(init_val)
        self.num = 2**(self.n-1).bit_length()
        self.ide_ele = ide_ele
        self.segfunc = segfunc
        self.seg = [ide_ele]*2*self.num
        # set_val
        for i in range(self.n):
            self.seg[i+self.num] = init_val[i]
        # built
        for i in range(self.num-1, 0, -1):
            self.seg[i] = self.segfunc(self.seg[2*i], self.seg[2*i+1])

    def update(self, k, x):
        k += self.num
        self.seg[k] = x
        while k:
            k = k >> 1
            self.seg[k] = self.segfunc(self.seg[2*k], self.seg[2*k+1])

    def query(self, l, r):
        if r <= l:
            return self.ide_ele
        l += self.num
        r += self.num
        res = self.ide_ele
        while l < r:
            if r & 1:
                r -= 1
                res = self.segfunc(res, self.seg[r])
            if l & 1:
                res = self.segfunc(res, self.seg[l])
                l += 1
            l = l >> 1
            r = r >> 1
        return res

def segfunc(x, y):
    if x <= y:
        return x
    else:
        return y

ide_ele = 10**18

class LCA:
    def __init__(self, g, root):
        # g: adjacency list
        # root
        self.n = len(g)
        self.root = root

        s = [self.root]
        self.parent = [-1]*self.n
        self.child = [[] for _ in range(self.n)]
        visit = [-1]*self.n
        visit[self.root] = 0
        while s:
            v = s.pop()
            for u in g[v]:
                if visit[u] == -1:
                    self.parent[u] = v
                    self.child[v].append(u)
                    visit[u] = 0
                    s.append(u)

        # Euler tour
        tank = [self.root]
        self.eulerTour = []
        self.left = [0]*self.n
        self.right = [-1]*self.n
        self.depth = [-1]*self.n

        eulerNum = -1
        de = -1

        while tank:
            v = tank.pop()
            if v >= 0:
                eulerNum += 1
                self.eulerTour.append(v)
                self.left[v] = eulerNum
                self.right[v] = eulerNum
                tank.append(~v)
                de += 1
                self.depth[v] = de
                for u in self.child[v]:
                    tank.append(u)
            else:
                de -= 1
                if ~v != self.root:
                    self.eulerTour.append(self.parent[~v])
                    eulerNum += 1
                    self.right[self.parent[~v]] = eulerNum

        #A = [self.depth[e] for e in self.eulerTour]
        A = [0]*(2*self.n-1)
        for i, e in enumerate(self.eulerTour):
            A[i] = self.depth[e]*(2*self.n-1)+i
        self.seg = SegTree(A, ide_ele, segfunc)

    def getLCA(self, u, v):
        # u, v: 0-indexed
        p = min(self.left[u], self.left[v])
        q = max(self.right[u], self.left[v])+1
        m = self.seg.query(p, q)
        return self.eulerTour[m%(2*self.n-1)]

import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n, m = map(int, input().split())
g = [[] for i in range(n)]
for i in range(n-1):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    g[a].append(b)
    g[b].append(a)

cd = CentroidDecomposition(g)
lca = LCA(g, 0)
#print(cd.cdparent)
min_dist = [0]*n
for i in range(n):
    min_dist[i] = lca.depth[i]

#print(min_dist)

for i in range(m):
    t, v = map(int, input().split())
    v -= 1
    if t == 1:
        cur = v
        while cur != -1:
            l = lca.getLCA(cur, v)
            d = lca.depth[cur]+lca.depth[v]-2*lca.depth[l]
            min_dist[cur] = min(min_dist[cur], d)
            cur = cd.cdparent[cur]
    else:
        ans = n
        cur = v
        while cur != -1:
            l = lca.getLCA(cur, v)
            d = lca.depth[cur]+lca.depth[v]-2*lca.depth[l]
            ans = min(ans, d+min_dist[cur])
            cur = cd.cdparent[cur]
        print(ans)