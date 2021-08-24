
def tobase(num,base):
    nnum = ''
    rem = 0
    while num > 0:
#        print num,base
        num,rem = divmod(num,base)
        nnum = str(rem) + nnum
    return nnum

def sqsum(num,base):
    sum = 0
    sq = 0
    for n in num:
        sq = (int(n,base) ** 2)
        sum += sq
    return tobase(sum,base)

def ishappy(num,base):
    avoidloop = []
    #print 'in ishappy [%s] [%d]' % (num,base)
    nnum = tobase(num,base)
    while 1:
        #print '[%s] [%d]' % (nnum,base)
        nnum = sqsum(nnum,base)
        if nnum in avoidloop:
            if int(nnum) == 1:
                return 1
            else:
                return 0
        else:
            avoidloop.append(nnum)
    if int(nnum) == 1:
        return 1
    return 0
    
import fileinput

infile = fileinput.input()

params = infile.readline()

T = int(params.strip())
bases = []


for t in range(T):
    bases = [int(p) for p in infile.readline().strip().split()]
    bases.sort()
    i = 2
    while i:
        trynext = 0
        for base in bases:
            #print 'trying base [%d]' % base
            if ishappy(i,base) == 0:
                trynext = 1
                break
        if trynext == 0:
            print 'Case #%d: %d' % (t+1, i)
            break
        i += 1

infile.close()