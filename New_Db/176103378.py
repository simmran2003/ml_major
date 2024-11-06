from sys import stdin
input=lambda :stdin.readline()[:-1]

n,m=map(int,input().split())
a=list(map(int,input().split()))
cnt=[0]*(m+1)
for i in a:
  if i<=m:
    cnt[i]+=1

for i in range(m,-1,-1):
  if cnt[i]==0:
    continue
  for j in range(2*i,m+1,i):
    cnt[j]+=cnt[i]

mx=max(cnt)
if mx==0:
  print(1,0)
  print()
  exit()

idx=cnt.index(mx)
ans=[]
for i in range(n):
  if idx%a[i]==0:
    ans.append(i+1)

print(idx,mx)
print(*ans)