from functools import cmp_to_key

def comp(a, b):
    p = a + b
    q = b + a
    if p < q:
        return -1
    if p == q:
        return 0
    else:
        return 1
ckey = cmp_to_key(comp)

n = int(input())
words = []
for i in range(n):
    s = input()
    words.append(s)

words = sorted(words, key = ckey)

s = ''

for i in range(n):
    s += words[i]

print(s)