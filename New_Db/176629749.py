from functools import cmp_to_key

def func(strings):
  strings.sort(key=cmp_to_key(lambda a,b: -1 if (a + b) < (b + a) else 0))
  return "".join(strings)

num = int(input())
strings = []
for _ in range(num):
  strings.append(input())
print(func(strings))