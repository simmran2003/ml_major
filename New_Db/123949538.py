n, p = [int(x) for x in input().split()]
ls = [input() for _ in range(n)]
apples = 1
sum = p // 2
for i in reversed(range(n - 1)):
    sum += p * apples
    apples = apples * 2
    if ls[i] == "halfplus":
        sum += p // 2
        apples += 1
print(sum)