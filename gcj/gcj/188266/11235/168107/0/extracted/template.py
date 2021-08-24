import sys

ifs = file("input.txt")
ofs = file("output.txt", "w")

isdataset = {}
def ReadInts(input = ifs):
    return list(map(int, input.readline().strip().split(" ")))


def GetMatrix(rows, cols, value=0):
    return [[value for i in range(rows)] for j in range(cols)]

def GetNext(num, base):
    digits = []
    while num > 0:
        digits.append(num % base)
        num = num / base
    sum = 0
    for i in digits:
        sum += i*i
    return sum
    

def IsHappy(num, base):
    state = isdataset.get((num,base), -1)
    if state != -1:
        return state
    
    intermedia = [num]
    while(state == -1):
        next = GetNext(num,base)
        if (next == 1):
            state = 1
            break
        if (next == 0):
            state = 0
            break
        
        state = isdataset.get((next,base), -1)
        if state == -1:
            if next in intermedia:
                state = 0
                break
            intermedia.append(next)
            num = next
            continue
        break
    for item in intermedia:
        isdataset[(item, base)] = state
    return state

def FindMin(baselist):
    find = False
    min = 2
    while (not find):
        find = True
        for base in baselist:
            if not IsHappy(min, base):
                find = False
                break
        if find:
            break
        min += 1
    return min
        
caseNo = ReadInts()[0]
for i in range(1, caseNo+1): 
    print >> ofs, "Case #%d:" % i, FindMin(ReadInts())

ifs.close()
ofs.close()



