n = int(input())
p = [int(x) for x in input().split()]
s = input()

def get_pref(c):
    pref = [0]*n
    pref[0] = p[0] if s[0] == c else 0
    for i in range(1, n):
        pref[i] = pref[i-1]
        pref[i] += p[i] if s[i] == c else 0
    return pref

def get_suff(c):
    suff = [0]*n
    suff[-1] = p[-1] if s[-1] == c else 0
    for i in reversed(range(0, n-1)):
        suff[i] = suff[i+1]
        suff[i] += p[i] if s[i] == c else 0
    return suff

pref_flip = get_pref('A')
pref_keep = get_pref('B')
suff_flip = get_suff('A')
suff_keep = get_suff('B')

ans = max(
    pref_flip[-1], suff_flip[0],
    pref_keep[-1], suff_keep[0]
)

for i in range(n-1):
    ans = max(
        ans,
        pref_flip[i] + suff_keep[i+1],
        pref_keep[i] + suff_flip[i+1]
    )
print(ans)