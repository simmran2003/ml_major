n, m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
lcm_lens = [0] * (m + 1)
occs = [[] for _ in range(m + 1)]
for i in range(n):
    if a[i] <= m:
        occs[a[i]].append(i)
for i in range(1, m + 1):
    if len(occs[i]) >= 0:
        for j in range(i, m + 1, i):
            lcm_lens[j] += len(occs[i])
best = 1
max_len = 0
for i in range(m + 1):
    if lcm_lens[i] > max_len:
        best = i
        max_len = lcm_lens[i]

if max_len == 0:
    print(1, 0)
else:
    res = []
    for i in range(n):
        if best % a[i] == 0:
            res.append(i)
    print(best, len(res))
    print(*[x + 1 for x in res])
