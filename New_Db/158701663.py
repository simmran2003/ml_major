n,t=int(input()),list(map(int,input().split()))
b=[q*(d=='B')for q,d in zip(t,input())]
v=sum(b)
u=sum(t)-v
s=max(u,v)
for i,j in zip(b,t):
    u+=2*i-j
    v+=j-2*i
    s=max(u,v,s)
print(s)