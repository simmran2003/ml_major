n, p = [int(i) for i in input().split()]
ans = 0
free = 0
arr = [input().rstrip()[-1] == "s" for _ in range(n)]

for x in arr[::-1]:
    if x:
        ans = ans * 2 + 1
        free += 1
    else:
        ans *= 2

print(ans*p - p//2*free)