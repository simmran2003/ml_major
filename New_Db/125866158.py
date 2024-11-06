from collections import defaultdict
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = list(map(int, input().split()))
cnt = defaultdict(lambda : 0)
for i in a:
    cnt[i] += 1
s = [0] * (m + 1)
for i in range(1, m + 1):
    if cnt[i]:
        c = cnt[i]
        j = i
        while j < m + 1:
            s[j] += c
            j += i
l, k = 0, 0
for i in range(1, m + 1):
    if k < s[i]:
        l, k = i, s[i]
ans = []
if not k:
    l = 1
if k:
    for i in range(n):
        if not l % a[i]:
            ans.append(i + 1)
print(l, k)
print(*ans)