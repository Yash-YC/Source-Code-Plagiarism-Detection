def happy_test(num):
    total = 0
    for i in num:
        total += int(i)
    if total == 1:
        return True
    else:
        return False
def toBase(num,base):
    number = ""
    while num > 0:
        number = str(num % base) + number
        num /= base
    if number == "": number = "0"
    return number
T = int(raw_input())
for c in xrange(T):
    bases = map(int,raw_input().split(" "))
    num = 2
    while True:
        for i in bases:
            use = toBase(num,i)
            d = {}
            Test = False
            while d.get(use,None) == None:
                d[use] = True
                if happy_test(use):
                    Test = True
                    break
                newint = 0
                for j in use:
                    newint += int(j)**2
                use = toBase(newint,i)
            if Test:
                continue
            else:
                break
        if Test:
            print "Case #%d: %d" % (c+1,num)
            break
        num += 1
                
            
        
    
