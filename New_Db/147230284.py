n = int(input())
P = list(map(int, input().split()))
s = list(str(input()))

A = [0]*(n+1)
B = [0]*(n+1)
for i in range(n):
    if s[i] == 'A':
        A[i+1] += P[i]
    else:
        B[i+1] += P[i]
from itertools import accumulate
A = list(accumulate(A))
B = list(accumulate(B))

ans = 0
for i in range(n+1):
    ans = max(ans, A[i]+B[-1]-B[i])

P.reverse()
s.reverse()

A = [0]*(n+1)
B = [0]*(n+1)
for i in range(n):
    if s[i] == 'A':
        A[i+1] += P[i]
    else:
        B[i+1] += P[i]
A = list(accumulate(A))
B = list(accumulate(B))
for i in range(n+1):
    ans = max(ans, A[i]+B[-1]-B[i])
print(ans)
