import sys
input = lambda :sys.stdin.readline()[:-1]
ni = lambda :int(input())
na = lambda :list(map(int,input().split()))
yes = lambda :print("yes");Yes = lambda :print("Yes");YES = lambda : print("YES")
no = lambda :print("no");No = lambda :print("No");NO = lambda : print("NO")
#######################################################################
n,m = na()
a = na()
b = [0] * (1 + m)

for i in range(n):
    if a[i] <= m:
        b[a[i]] += 1

if sum(b) == 0:
    print(1, 0)
    print()
    exit()
for i in range(m, 0, -1):
    for j in range(i * 2, m + 1, i):
        b[j] += b[i]

k = b.index(max(b))

ans = []
for i in range(n):
    if k % a[i] == 0:
        ans.append(i+1)
print(k, max(b))
print(*ans)
