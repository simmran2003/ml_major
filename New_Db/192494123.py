# LUOGU_RID: 101607313
n, p = map(int, input().split())
t = 0
for i in range(n):
    if input() == 'halfplus':
        t |= 2**i
ans = 0
while t:
    ans += t
    t //= 2
print(ans * p // 2)