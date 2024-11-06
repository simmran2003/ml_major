r,h=map(int,input().split())
z=h//r
ans=z*2+1;h-=r*z
if h*h*4>=r*r:ans+=1
if h*h*4>=r*r*3:ans+=1
print(ans)