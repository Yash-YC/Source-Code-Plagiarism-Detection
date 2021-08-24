n=input()

def sum_s(n):
    return sum([int(x)*int(x) for x in str(n)])

def solve(n,base):
    n=tobase(base,n)
    x=tobase(base,sum_s(int(n)))
    mem=[x]
    while x!='1': 
        if x=='1':
            return True
        if x==str(n):
            return False

        x=tobase(base,sum_s(int(x)))
        if x in mem:
            return False
        mem.append(x)
    if x=='1':
        #print base, n, mem
        return True
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

bin = lambda n: tobase(2,n)

for i in range(n):
    tt=raw_input()
    b=[int(x) for x in tt.split(' ')]
    #print b
    flag = False
    ptr=2
    while not flag:
        f=True
        for base in b:
            if f:
                if not solve(ptr,base):
                    f=False
        if f:
            print "Case #" + str(i+1)+": "+ str(ptr)
            break
        ptr+=1