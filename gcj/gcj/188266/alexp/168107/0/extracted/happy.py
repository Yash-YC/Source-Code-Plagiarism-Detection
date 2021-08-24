#!/usr/bin/python

from sets import Set;

def is_happy(nn, b):
	n=nn
	seen = Set();
	while (n != 1):
		seen.add(n);
		m=0;
		while (n != 0):
			m+=(n%b)**2;
			n/=b;
		if m in seen:
			return False
		n=m;
	return True


f = open("test");

T = int(f.readline());

for i in range (0,T):
	bases = [ int(b) for b in f.readline().split() ]
	tried = 2L;
	while True:
		for b in bases:
			if not is_happy(tried,b):
				break;
		else:
			print "Case #"+str(i+1)+": "+str(tried);
			break
		tried+=1;

