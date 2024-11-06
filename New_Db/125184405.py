n,p = map(int,input().split())
s,ans,num = [1 if input().strip() == 'halfplus'else 0 for i in range(n)],0,0
for i in range(n - 1,-1,-1):
    num *= 2
    if s[i]:
        num += 1
    ans += num
print(ans * p // 2)