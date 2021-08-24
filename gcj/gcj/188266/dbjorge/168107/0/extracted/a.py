'''Google CodeJam 2009 - Round 1A - Problem A

@author: Dan Bjorge
'''import pickle

#fileprefix = 'A-small-ex'
fileprefix = 'A-small-attempt0'
#fileprefix = 'A-large'

filepath = ''
filepathname = filepath + fileprefix
infilename = filepathname + '.in'
outfilename = filepathname + '.out'
lines = open(infilename, 'rU').read().split("\n")
outfile = open(outfilename, 'w+')

#This will sometimes, but not often, change
linenum = 1
cases = int(lines[0])
deps = {}happy = 0sad = 1checking = 2maxr = 1000try:    hf = open("happydict.pkl", 'rb')    happy = pickle.load(hf)except:    print("load error")    happy = {}    for base in range(2,11):        happy[base] = [sad,happy]+ [checking for i in range(maxr)]def getNext(n, base):    on = n    r = 0    while n >= base:        r += (n % base) ** 2        n = n // base            if n > 0:        r += (n ** 2)            #print(str(on)+"->"+str(n)+" _"+str(base))    return rdef solve(bases):
        found = False    c = 1    while not found:        c += 1        good = True        for base in bases:            nc = c            loop = []            result = 2            while True:                #print (happy)                #print (base)                #print (nc)                if nc < maxr:                    if happy[base][nc] != 2:                        result = happy[base][nc]                        break                    if nc in loop:                        result = sad                        break                    loop.append(nc)                nc = getNext(nc, base)                            for q in loop:                happy[base][q] = result                        if result is sad:                good = False                break                            #print ("tryied "+str(c)+" for base "+str(base)+", got loop "+str(loop)+" ("+str(happy[base][c])+")")                if good:            return c#        if c > maxr:#            print("shit shit")#            print()#            return -1        for casenum in range(1, cases+1):
    #Begin parsing for one problem starting at line linenum
    bases = [int(x) for x in lines[linenum].split(" ")]        
    out = solve(bases) #Assign solved value
    linenum+=1
    
    #End parsing - start outputting
    casestr = 'Case #'+str(casenum)+': '+str(out)
    print (casestr)
    outfile.write(casestr+"\n")pickle.dump(happy, open("happydict.pkl", 'wb'))