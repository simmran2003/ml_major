
n=int(input())

# taking array as input

lst = [int(item) for item in input().split()]

t=n/3
cnt1=0
cnt2=0
cnt3=0
cnt4=0
cnt4=0
cnt6=0
for i in lst:
	if i==5 or i==7:
		print("-1")
		exit()
	if i==1:
		cnt1+=1
	if i==2:
		cnt2+=1
	if i==3:
		cnt3+=1
	if i==4:
		cnt4+=1			 	
	if i==6:
		cnt6+=1	


if cnt1 !=t or cnt2+cnt3 != t or cnt4 +cnt6 !=t or cnt6<cnt3:
	print("-1")
	exit()	

for i in range(int(t)):
	if cnt2>0 and cnt4>0:
		print(1,2,4)
		cnt2-=1
		cnt4-=1

	elif cnt2>0 and cnt6>0:
		print(1,2,6)
		cnt2-=1
		cnt6-=1

	elif cnt3>0 and cnt6>0:
		print(1,3,6)
		cnt3-=1
		cnt6-=1			
	else:
		print(-1)
		exit()	













