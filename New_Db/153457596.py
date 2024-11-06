n, p = (int(x) for x in input().split())
b = [input() for _ in range(n)]

a = 0
ans = 0
for i in reversed(b):
    a *= 2
    if i == 'halfplus':
        a += 1
        ans += p//2
    ans += p * (a//2)

print(ans)