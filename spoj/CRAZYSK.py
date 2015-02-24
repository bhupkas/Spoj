#!usr/bin/python

t=int(raw_input())
while (t>0):
	te=map(int,raw_input().split())
	x=te[0]
	n=te[1]
	t-=1
	ans=te[0]
	num=x
	while(num>=n):
		v=num/n
		ans+=v
		num-=v*n
		num+=v
	print ans
