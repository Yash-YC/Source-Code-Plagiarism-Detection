
def tobase(base,number):
    global tb
    def tb(b,n,result=''):
        if n == 0: return result
        else: return tb(b,n/b,str(n%b)+result)

    if type(base) != type(1):
        raise TypeError, 'invalid base for tobase()'
    if base <= 0:
        raise ValueError, 'invalid base for tobase(): %s' % base
    if type(number) != type(1) and type(number) != type(1L):
        raise TypeError, 'tobase() of non-integer'
    if number == 0:
        return '0'
    if number > 0:
        return tb(base, number)
    if number < 0:
        return '-' + tb(base, -1*number)



def SumSqr(A,base=10):
	sum=reduce(lambda x,y: y+x, map(lambda x:int(x,base)**2,A))
	return tobase(base, sum)

def CheckInBase(Num,base=10):
	A = tobase(base,Num)
	Seen = {A:0}
	#print "saw ",A
	nex = SumSqr(A,base)
	while not Seen.has_key(nex):
		if nex=='1':
			return True
		Seen[nex]=0
		#print "saw", nex
		nex = SumSqr(nex,base)
	#print "saw again",nex
	return False
		
	
def main():
	print "2 in 10 is ", CheckInBase(2)
	print "82 in 10 is", CheckInBase(82)
	print "143 in 3 is", CheckInBase(143,3)

if __name__ == '__main__':
	main()
