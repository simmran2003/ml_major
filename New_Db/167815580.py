import functools
def cmp(x: str, y: str):
    if (x+y) < (y+x):
        return -1
    elif (x+y) > (y+x):
        return 1
    else:
        return 0

test = int(input())

strings = []

for i in range(test):
    x = input()
    strings.append(x)

sort_strings = sorted(strings, key=functools.cmp_to_key(cmp))

for i in sort_strings:
    print(i, end="")
