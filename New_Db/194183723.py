import sys
input = lambda :sys.stdin.readline()[:-1]
ni = lambda :int(input())
na = lambda :list(map(int,input().split()))
yes = lambda :print("yes");Yes = lambda :print("Yes");YES = lambda : print("YES")
no = lambda :print("no");No = lambda :print("No");NO = lambda : print("NO")
#######################################################################
n, p = na()
s = [input()for i in range(n)]
ans = 0
res = 0
for i in range(n-1,-1,-1):
    if s[i] == "halfplus":
        ans = ans * 2 + 1
    else:
        ans = ans * 2
    res += ans

print(res * p // 2)
