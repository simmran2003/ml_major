import functools
n = int(input())
words = []
def compare(x,y):
    if x + y > y + x:
        return 1
    else:
        return -1
for x in range(n):
    s = input()
    words.append(s)
ans = sorted(words, key=functools.cmp_to_key((compare)))
for x in ans:
    print(x, end="")