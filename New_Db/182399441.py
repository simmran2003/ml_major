n=int(input())
nums=list(map(int,input().split()))
one=nums.count(1)
two=nums.count(2)
three=nums.count(3)
four=nums.count(4)
six=nums.count(6)
ans=[]
check=False
button=False
while(check==False):
    if one>=1 and two>=1 and four>=1:
        ans.append([1,2,4])
        one-=1
        two-=1
        four-=1
        button=True
    elif one>=1 and two>=1 and six>=1:
        ans.append([1,2,6])
        one-=1
        two-=1
        six-=1
        button=True
    elif one>=1 and three>=1 and six>=1:
        ans.append([1,3,6])
        one-=1
        three-=1
        six-=1
        button=True
    else:
        check=True
if one!=0 or two!=0 or three!=0 or four!=0 or six!=0:
    print(-1)       
elif button==False or 5 in nums or 7 in nums:
    print(-1)      
else:
    for item in ans:
        print(*item)      
