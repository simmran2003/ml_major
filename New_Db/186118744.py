n = int(input())
lst = list(map(int, input().split()))
cnt = [0]*8
ans = False

for i in range(n):
    cnt[lst[i]]+=1


if (cnt[5]==0 and cnt[7]==0 and cnt[2]>=cnt[4] and cnt[1]==cnt[4]+cnt[6] and cnt[2]+cnt[3]==cnt[4]+cnt[6]):
    for i in range(cnt[4]):
        print("1 2 4")
    
    cnt[2] -= cnt[4]
    
    for i in range(cnt[2]):
        print("1 2 6")
    
    for i in range(cnt[3]):
        print("1 3 6")
        
else:
    print(-1)
