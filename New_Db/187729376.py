n = int(input())
arr = list(map(int, input().split()))
count1 = 0
count2 = 0
count3 = 0
count4 = 0
count6 = 0
for i in range(len(arr)):
    if(arr[i] == 1):
        count1 += 1
    elif(arr[i] == 2):
        count2 += 1
    elif(arr[i] == 3):
        count3 += 1
    elif(arr[i] == 4):
        count4 += 1
    elif(arr[i] == 6):
        count6 += 1
if(count1 != n//3 or count2+count3 != count1 or count4+count6 != count1 or count3 > count6):
    print(-1)
else:
    for i in range(n//3):
        print(1, end=" ")
        if(count2 != 0):
            print(2,end = " ")
            count2 -= 1
        else:
            print(3,end = " ")
            count3 -= 1
        if(count4 != 0):
            print(4,end = " ")
            count4 -= 1
        else:
            print(6,end = " ")
            count6 -= 1
        print()
