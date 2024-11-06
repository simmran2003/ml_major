n = int(input())
numbers = [int(num) for num in input().split(" ", n-1)]
a=b=c=d=e=f=0
for num in numbers:
    if num==1:
        a += 1
    if num==2:
        b += 1
    if num==3:
        c += 1
    if num==4:
        d += 1
    if num==6:
        e += 1
    if num==5 or num==7:
        f = 1
k = int((n/3)-c-d)
if a==(n/3) and b+c==(n/3) and d+e==(n/3) and e>=c and b>=d:
    print(d*"1 2 4\n", end="")
    print(c*"1 3 6\n", end="")
    print(k*"1 2 6\n")
else:
    print(-1)