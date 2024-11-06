from operator import is_
import sys
from collections import deque
import math
from array import array

input = sys.stdin.readline
n, m = map(int,input().split())
INF = 2*n

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


# try:
G = Graph(n)
G.input()

buf = []
BUF_LIM = round(math.sqrt(m))
def add_node(u):
    global buf
    buf.append(u)
    if len(buf) >= BUF_LIM:
        G.update_distance(buf)
        buf = []

for _ in range(m):
    t, u = map(int, input().split())
    u -= 1
    if t == 1:
        add_node(u)
    else:
        # all nodes in G or buf
        ans = G.get_distance(u)
        for v in buf:
            ans = min(ans, G.get_pair_distance(u,v))
        print(ans)
# except Exception as e:
#     print(e)