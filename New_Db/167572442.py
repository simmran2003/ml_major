import sys
input = sys.stdin.readline

n = int(input())
w = list(map(int, input().split()))
s = input()[:-1]
x = 0
x = sum(w[i] for i in range(n) if s[i] == 'B')

c = d = x
for i in range(n):
    if s[i] == 'A':
        c += w[i]
    else:
        c -= w[i]
    x = max(c, x)

for i in range(n-1, -1, -1):
    if s[i] == 'A':
        d += w[i]
    else:
        d -= w[i]
    x = max(d, x)

print(x)
