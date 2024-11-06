import heapq
n = int(input())



arr = [int(k) for k in input().split()]

def helper():
    obj = {}
    for el in arr:
        if el == 5 or el == 7:
            return -1
        obj[el] = obj.get(el, 0) + 1

    num_groups = n // 3
    big = []

    if obj.get(1, 0) != num_groups:
        return -1

    for _ in range(num_groups):
        big.append([1, -1, -1])

    if obj.get(6, 0) + obj.get(4, 0) != num_groups:
        return -1

    if obj.get(2, 0) + obj.get(3, 0) != num_groups:
        return -1

    i = 0
    while obj.get(6, 0) > 0:
        big[i][2] = 6
        obj[6] -= 1
        if obj.get(3, 0) >= 1:
            big[i][1] = 3
            obj[3] -= 1
        elif obj.get(2, 0) >= 1:
            big[i][1] = 2
            obj[2] -= 1
        else:
            return -1
        i += 1

    while obj.get(4, 0) > 0:
        big[i][2] = 4
        obj[4] -= 1
        if obj.get(2, 0) >= 1:
            big[i][1] = 2
            obj[2] -= 1
        else:
            return -1
        i += 1

    for el in big:
        if any(k == -1 for k in el):
            return -1

    return big
    
    

res = helper()

if res == -1:
    print(-1)
else:
    for el in res:
        print(' '.join([str(j) for j in el]))
    