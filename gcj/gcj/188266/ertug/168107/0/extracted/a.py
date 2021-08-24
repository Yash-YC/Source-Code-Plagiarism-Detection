# ertug (Ertug Karamatli)

import sys
import re

f = file(sys.argv[1])

ln = 0

def convbase(num, n):
    new_num_string = ''
    current = int(num)
    while current!=0:
        remainder = current % n
        remainder_string = str(remainder)
        new_num_string = remainder_string + new_num_string
        current = current / n
    return new_num_string

def ishappy(num, n, first = False, depth = 0, last_num = 0):
    if first:
        num = convbase(num, n)
    #print num, n ,first, depth
    depth += 1
    if depth >= 20: return False
    if str(last_num) == str(num): return False
    if num == 1 or num == '1': return True
    s = 0
    for d in str(num):
        s += pow(int(d),2)
    s = convbase(s, n)
    last_num = num
    return ishappy(s, n, False, depth, last_num)


#print ishappy(143,6,True)
case = 1
for line in f:
    line = line.strip()
    if line == '': continue
    if ln != 0:
        bases = [int(b) for b in line.split(' ')]
        #print bases
        anymatch = False
        for i in xrange(2,100000):
            cnt = True
            matched = False
            while cnt:
                matched = False
                for base in bases:
                    h = ishappy(i, base, True)
                    if h:
                        cnt = False
                        matched = True
                    else:
                        cnt = False
                        matched = False
                        break
                if matched:
                    break
            if matched:
                print 'Case #%s: %s' % (case, i)
                anymatch = True
                break
        if anymatch == False:
            print 'NOOO'
            break
        case += 1


    ln += 1

