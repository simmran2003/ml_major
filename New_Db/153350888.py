def solv(r,h):
    ans = h//r*2
    h  %= r
    if h*2<r: return ans+1
    return ans+2 if 3*r*r>4*h*h else ans+3

r,h = map(int,input().split())
print(solv(r,h))

