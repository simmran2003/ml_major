n=int(input())+2 
arr=[0]+list(map(int,input().split()))+[0]
s='x'+input()+'x'
aprfx=[0]*n 
prfx=[0]*n
for i in range(1,n-1):
    prfx[i]=prfx[i-1]+arr[i] 
    if s[i]=='A':
        aprfx[i]+=arr[i]
    aprfx[i]+=aprfx[i-1] 
ans=prfx[n-2]-aprfx[n-2]
for i in range(n-1):
    ans=max(ans,aprfx[i]+prfx[n-2]-prfx[i]-(aprfx[n-2]-aprfx[i]),prfx[i]-aprfx[i]+(aprfx[n-2]-aprfx[i]))
print(ans)    
    
