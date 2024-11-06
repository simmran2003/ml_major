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

class HLD:
    def __init__(self, g):
        self.g = g
        self.n = len(g)
        self.parent = [-1]*self.n
        self.size = [1]*self.n
        self.head = [0]*self.n
        self.preorder = [0]*self.n
        self.k = 0
        self.depth = [0]*self.n

        for v in range(self.n):
            if self.parent[v] == -1:
                self.dfs_pre(v)
                self.dfs_hld(v)

    def dfs_pre(self, v):
        g = self.g
        stack = [v]
        order = [v]
        while stack:
            v = stack.pop()
            for u in g[v]:
                if self.parent[v] == u:
                    continue
                self.parent[u] = v
                self.depth[u] = self.depth[v]+1
                stack.append(u)
                order.append(u)

        # 隣接リストの左端: heavyな頂点への辺
        # 隣接リストの右端: 親への辺
        while order:
            v = order.pop()
            child_v = g[v]
            if len(child_v) and child_v[0] == self.parent[v]:
                child_v[0], child_v[-1] = child_v[-1], child_v[0]
            for i, u in enumerate(child_v):
                if u == self.parent[v]:
                    continue
                self.size[v] += self.size[u]
                if self.size[u] > self.size[child_v[0]]:
                    child_v[i], child_v[0] = child_v[0], child_v[i]

    def dfs_hld(self, v):
        stack = [v]
        while stack:
            v = stack.pop()
            self.preorder[v] = self.k
            self.k += 1
            top = self.g[v][0]
            # 隣接リストを逆順に見ていく（親 > lightな頂点への辺 > heavyな頂点 (top)）
            # 連結成分が連続するようにならべる
            for u in reversed(self.g[v]):
                if u == self.parent[v]:
                    continue
                if u == top:
                    self.head[u] = self.head[v]
                else:
                    self.head[u] = u
                stack.append(u)

    def for_each(self, u, v):
        # [u, v]上の頂点集合の区間を列挙
        while True:
            if self.preorder[u] > self.preorder[v]:
                u, v = v, u
            l = max(self.preorder[self.head[v]], self.preorder[u])
            r = self.preorder[v]
            yield l, r # [l, r]
            if self.head[u] != self.head[v]:
                v = self.parent[self.head[v]]
            else:
                return

    def for_each_edge(self, u, v):
        # [u, v]上の辺集合の区間列挙
        # 辺の情報は子の頂点に
        while True:
            if self.preorder[u] > self.preorder[v]:
                u, v = v, u
            if self.head[u] != self.head[v]:
                yield self.preorder[self.head[v]], self.preorder[v]
                v = self.parent[self.head[v]]
            else:
                if u != v:
                    yield self.preorder[u]+1, self.preorder[v]
                break

    def subtree(self, v):
        # 頂点vの部分木の頂点集合の区間 [l, r)
        l = self.preorder[v]
        r = self.preorder[v]+self.size[v]
        return l, r

    def lca(self, u, v):
        # 頂点u, vのLCA
        while True:
            if self.preorder[u] > self.preorder[v]:
                u, v = v, u
            if self.head[u] == self.head[v]:
                return u
            v = self.parent[self.head[v]]

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
hld = HLD(g)
#print(cd.cdparent)
min_dist = [0]*n
for i in range(n):
    min_dist[i] = hld.depth[i]

#print(min_dist)

for i in range(m):
    t, v = map(int, input().split())
    v -= 1
    if t == 1:
        cur = v
        while cur != -1:
            l = hld.lca(cur, v)
            d = hld.depth[cur]+hld.depth[v]-2*hld.depth[l]
            min_dist[cur] = min(min_dist[cur], d)
            cur = cd.cdparent[cur]
    else:
        ans = n
        cur = v
        while cur != -1:
            l = hld.lca(cur, v)
            d = hld.depth[cur]+hld.depth[v]-2*hld.depth[l]
            ans = min(ans, d+min_dist[cur])
            cur = cd.cdparent[cur]
        print(ans)
