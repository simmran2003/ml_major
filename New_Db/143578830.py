s = input().split()
(n,m,s,f) = (int(i) for i in s)
steps = []

for i in range(m):
	p = input().split()
	p = [int(i) for i in p]
	steps.append(p)

if(s<f):
	t = ''
	init = s
	start = 1
	flag = 0
	for i in range(m):
		curr_l = steps[i][1]
		curr_r = steps[i][2]
		while(start < steps[i][0]):
			if(init == f):
				flag = 1
				break
			else:
				t += 'R'
				init += 1
			start += 1
		if(flag == 1):
			break
		else:
			if(init == f):
				flag = 1
				break
			if(start == steps[i][0]):
				if((init <= curr_r and init >= curr_l) or (init+1 <= curr_r and init+1 >= curr_l) ):
					t += 'X'
				else:
					t += 'R'
					init += 1
		start += 1
	while(init < f):
		init += 1
		t += 'R'

else:
	t = ''
	init = s
	start = 1
	flag = 0
	for i in range(m):
		curr_l = steps[i][1]
		curr_r = steps[i][2]
		while(start < steps[i][0]):
			if(init == f):
				flag = 1
				break
			else:
				t += 'L'
				init -= 1
			start += 1
		if(flag == 1):
			break
		else:
			if(init == f):
				flag = 1
				break
			if(start == steps[i][0]):
				if((init <= curr_r and init >= curr_l) or (init-1 <= curr_r and init-1 >= curr_l)):
					t += 'X'
				else:
					t += 'L'
					init -= 1
		start += 1
	while(init > f):
		t += 'L'
		init -= 1

print(t)





		


