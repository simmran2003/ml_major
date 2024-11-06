n=int(input())
l=list(map(int,input().split()))
for i in l:
    if i==5 or i==7:
        print("-1")
        quit()
a,b,c,d,e=l.count(1),l.count(2),l.count(3),l.count(4),l.count(6)
if a!=b+c:
    print(-1)
elif a!=(d+e):
    print(-1)
elif c>e or d>b:
    print(-1)
else:
    while c:
        print("1 3 6")
        c-=1
        a-=1
        e-=1
    while e:
        print("1 2 6")
        e-=1
        a-=1
        c-=1
    while d:
        print("1 2 4")
        d-=1
    