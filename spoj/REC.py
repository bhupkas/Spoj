#!usr/bin/python

def func(p,q,M):
	if q==0:
		return 1
	elif q==1:
		return p%M
	te=func(p,q/2,M)%M
	te = (te*te)%M
	if q%2==1:
		return (te*p)%M
	return te%M


t=int(raw_input())
while t>0:
	t=t-1
	te=map(int,raw_input().split())
	a=te[0]
	b=te[1]
	n=te[2]
	M=te[3]
	a=a%M
	b=b%M
	if M==1:
		print '0'
		continue
	elif n==0:
		print '1'
		continue
	elif a==0:
		print b
		continue
	elif a==1:
		print (1+b*n)%M 
		continue
	ans=0
	temp=func(a,n,M)%M;
	temp=temp%M
	ans+=temp
	ans= M+ans+b*((temp-1)*func(a-1,M-2,M))
	print func(a-1,M-2,M)%M
	while ans<0:
		ans+=M
	print (ans+M)%M



