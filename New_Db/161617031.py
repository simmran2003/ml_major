import sys
input = sys.stdin.readline

n, p = map(int, input().split())
x = 0
c = 0
g = [input()[:-1] for _ in range(n)]
for i in range(n-1,-1,-1):
    if g[i] == 'half':
        x *= 2
    else:
        x = x*2 + 1
        c += 0.5
print(int((x-c)*p))
