
import string
import re


def str2(num, base) :
    result = ''
    while True:
        num, rdigit = divmod( num, base)
        result = str(rdigit) + result
        if num==0:
            return result
        

def happyNum(num, base) :
    d = dict()
    sum = num
    while not sum == 1:
        strNum = str2(sum,base)
        sum = 0
        for i in range(0,len(strNum)):
            sum += int(strNum[i])**2
        if sum in d:
            return False
        else:
            d[sum] = True
    return True


s = raw_input()
numCases = int(s)

    
for i in range(numCases):
    s = raw_input()
    a = s.split()
    num = 2
    numNotFound = True
    while numNotFound:
        numNotFound = False
        for j in a:
            if not happyNum(num,int(j)):
                numNotFound = True
                num += 1
                break

    print "Case #{0}:".format(1+i), num
    

