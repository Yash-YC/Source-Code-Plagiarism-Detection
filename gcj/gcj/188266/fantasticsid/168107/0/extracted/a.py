n = int(raw_input
())

def inbase(k, j):
    l = []
    while j != 0:
        l.insert(0, j % k)
        j = j / k
    return l

def happy(k, j):
    l = []
    loopy = set()
    loopy.add(j)
    while j != 1:
        j = sum(map(lambda x: x**2, inbase(k, j)))
        if j in loopy:
            break
        else:
            loopy.add(j)
    if j == 1:
        return True
    else:
        return False
        


for i in range(n):
    l = map(int, raw_input().split())
    for j in range(2, 100000):
        ifhappy = False
        for k in l:
            if happy(k, j):
                ifhappy = True
                continue
            else:
                ifhappy = False
                break
        if ifhappy == True:
            print "Case #%d: %d"%(i+1, j)
            break


    
