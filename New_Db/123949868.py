n, p = [int(x) for x in input().split()]
ls = [input() for _ in range(n)]
apples = 0
halfs = 0
for i in range(n):
    if ls[i] == "halfplus":
        apples = apples | (1 << i)
        halfs += 1
print(apples * p - halfs * p // 2)
