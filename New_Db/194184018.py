import sys
input = lambda :sys.stdin.readline()[:-1]
ni = lambda :int(input())
na = lambda :list(map(int,input().split()))
yes = lambda :print("yes");Yes = lambda :print("Yes");YES = lambda : print("YES")
no = lambda :print("no");No = lambda :print("No");NO = lambda : print("NO")
#######################################################################
n = ni()
a = [0]+na()
s = input()
b = [0] * (1+n)

for i in range(n):
    a[i+1] += a[i]
    if s[i] == "A":
        b[i+1] += b[i] + a[i+1]-a[i]
    else:
        b[i+1] += b[i]
ans = 0
for i in range(n+1):
    ans = max(a[i]-b[i]+b[-1]-b[i], ans)
    ans = max(b[i]+ (a[-1]-a[i])-(b[-1]-b[i]), ans)

print(ans)
