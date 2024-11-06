from sys import stdin
input=lambda :stdin.readline()[:-1]

n,p=map(int,input().split())
s=[]
for _ in range(n):
  s.append(input())

ans=0
res=0
for i in s[::-1]:
  if i=='half':
    ans+=res*p
    res*=2
  else:
    ans+=(res)*p+p//2
    res*=2
    res+=1
print(ans)