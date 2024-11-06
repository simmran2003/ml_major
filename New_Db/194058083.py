from collections import Counter
n = int(input())
nums = Counter([int(i) for i in input().split()])
 
d= []
for _ in range(n//3):   
    if nums.get(1,0)>0     and nums.get (3,0)>0    and nums.get(6,0)>0:
        nums[1]-=1
        nums[3]-=1
        nums[6]-=1
        d.append("1 3 6")
    elif nums.get(1,0)>0  and nums.get (2,0)>0  and nums.get(6,0)>0:
        nums[1]-=1
        nums[2]-=1
        nums[6]-=1
        d.append("1 2 6")
    elif nums.get(1,0)>0   and nums.get (2,0)>0 and nums.get(4,0)>0:
        nums[1]-=1
        nums[2]-=1
        nums[4]-=1
        d.append("1 2 4")
    else:
        print("-1")
        break
if len(d)==n//3:
    for k in d:
        print(k)