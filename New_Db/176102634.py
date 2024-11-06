from sys import stdin
input=lambda :stdin.readline()[:-1]

n=int(input())
a=list(map(int,input().split()))
s=input()
ans=0
for i in range(n):
  if s[i]=='A':
    ans+=a[i]

def calc(a,s):
  mx=0
  tmp=0
  for i in range(n):
    if s[i]=='A':
      tmp-=a[i]
    else:
      tmp+=a[i]
    mx=max(mx,tmp)
  return mx

print(ans+max(calc(a,s),calc(a[::-1],s[::-1])))