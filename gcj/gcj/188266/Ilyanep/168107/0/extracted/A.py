# Tested locally with Python 2.6.2 on OS X 10.6.0
def isHappy(num, base, seen):
    if num is 1:
        return True
    if num in seen:
        return False
    seen.append(num)
    digits = []
    while num is not 0:
        digits.append(num % base)
        num = num/base
    newnum = 0
    for i in digits:
        newnum += i*i
    return isHappy(newnum, base, seen)

input = open('A-small.in','r')
output = open('A-small.out','w')
T = int(input.next())

for i in range(0,T):
    bays = input.next().split(' ')
    bases = []
    for j in bays:
        bases.append(int(j))
    
    foundHappy = True
    j = 2
    while True:
        for k in bases:
            if isHappy(j,k,[]) is not True:
                foundHappy = False
                break
            else:
                continue
        if foundHappy is False:
            foundHappy = True
            j+=1
        else:
            break
    output.write("Case #"+str(i+1)+": "+str(j)+"\n")
                

