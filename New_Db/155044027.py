import sys
input = sys.stdin.readline

n, p = map(int, input().split())
s = [input().rstrip() for _ in range(n)]
x = 0
for s0 in reversed(s):
    x *= 2
    if s0 == "halfplus":
        x += 2
ans = 0
p //= 2
for s0 in s:
    c = x // 2
    ans += c * p
    x -= c
    if s0 == "halfplus":
        x -= 1
print(ans)