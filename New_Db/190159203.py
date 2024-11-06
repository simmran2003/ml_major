n = int(input())
input_arr = input().split()
arr = []
sum = 0
for i in range(n):
    # if int(input_arr[i]) == 5 or int(input_arr[i]) == 7:
    #     break
    sum += int(input_arr[i])
    arr.append(int(input_arr[i]))
arr.sort()
a_arr = []
b_arr = []
c_arr = []
for i in range(len(arr)//3):
    a_arr.append(arr[i])
    b_arr.append(arr[i + (n//3)])
    c_arr.append((arr[i + ((2*n)//3)]))
possibel = True
for i in range(len(arr)//3):
    if(b_arr[i] % a_arr[i] == 0 and b_arr[i] > a_arr[i] and c_arr[i] % b_arr[i] == 0 and c_arr[i] > b_arr[i]):
        continue
    else:
        possibel = False
        print(-1)
        break
if possibel:
    for i in range(len(arr)//3):
        print(f'{a_arr[i]} {b_arr[i]} {c_arr[i]}')