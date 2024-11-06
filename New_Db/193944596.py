usable = [
    (1, 2, 4),
    (1, 2, 6),
    (1, 3, 6),
]

input()
cnter = [0] * 8
for x in map(int, input().split()):
    cnter[x] += 1

good = []
changes_made = True
while changes_made:
    cnter_prev = cnter[:]
    for i1, i2, i3 in usable:
        if cnter[i1] > 0 and cnter[i2] > 0 and cnter[i3] > 0:
            v = min((cnter[i1], cnter[i2], cnter[i3]))
            cnter[i1] -= v
            cnter[i2] -= v
            cnter[i3] -= v
            for _ in range(v):
                good.append((i1, i2, i3))
    changes_made = (cnter_prev != cnter) and (sum(cnter) > 0)

if sum(cnter) == 0:
    for e in good:
        print(' '.join(map(str, e)))
else:
    print(-1)