n, p = map(int, input().split())
S = []
for i in range(n):
    s = str(input())
    S.append(s)
cnt = 0
ans = 0
S.reverse()
for s in S:
    if s == 'half':
        ans += p*cnt
        cnt *= 2
    else:
        ans += p*cnt+p//2
        cnt *= 2
        cnt += 1
print(ans)
