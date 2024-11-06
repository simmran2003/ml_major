from collections import defaultdict, deque
import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def get_root(s):
    v = []
    while not s == root[s]:
        v.append(s)
        s = root[s]
    for i in v:
        root[i] = s
    return s

def unite(s, t):
    rs, rt = get_root(s), get_root(t)
    if not rs ^ rt:
        return
    if rank[s] == rank[t]:
        rank[rs] += 1
    if rank[s] >= rank[t]:
        root[rt] = rs
        size[rs] += size[rt]
    else:
        root[rs] = rt
        size[rt] += size[rs]
    return

def same(s, t):
    return True if get_root(s) == get_root(t) else False

def bfs(s):
    q = deque()
    q.append(s)
    dist = [-1] * n
    dist[s] = 0
    while q:
        i = q.popleft()
        di = dist[i]
        for j, c in G[i]:
            if dist[j] == -1:
                dist[j] = max(di, c)
                q.append(j)
    return dist

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
d = defaultdict(lambda : [])
ok = 1
for i in range(n):
    ai = a[i]
    for j in range(i + 1, n):
        if ai[j] ^ a[j][i]:
            ok = 0
            break
        d[ai[j]].append(i * n + j)
    if ai[i]:
        ok = 0
    if not ok:
        break
if ok:
    root = [i for i in range(n)]
    rank = [1 for _ in range(n)]
    size = [1 for _ in range(n)]
    G = [[] for _ in range(n)]
    c = 1
    for i in sorted(d.keys()):
        for x in d[i]:
            u, v = x // n, x % n
            if not same(u, v):
                unite(u, v)
                auv = a[u][v]
                G[u].append((v, auv))
                G[v].append((u, auv))
                c += 1
            if not c ^ n:
                break
        if not c ^ n:
            break
    for i in range(n):
        dist = bfs(i)
        ai = a[i]
        for x, y in zip(dist, ai):
            if x < y:
                ok = 0
                break
        if not ok:
            break
ans = "MAGIC" if ok else "NOT MAGIC"
print(ans)