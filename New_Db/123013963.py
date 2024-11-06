r,h = map(int,input().split())
ans = int(h//(r/2))
balloons = ans + (ans%2)
if balloons == 0:
    dist = r+1
else:
    dist = (((r/2)**2) + ((h - ((balloons//2)-1)*r)**2))**.5 
if dist >= r:
    balloons += 1
print(balloons)