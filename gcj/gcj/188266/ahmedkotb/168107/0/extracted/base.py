f_name = '0'
bs = []
base = 0
history = []
def toBase(x,base):
    result = ''
    while x > 0:
        result = str(x % base) + result
        x /= base
    if result == '': return '0'
    return result

def calc(x):
    global base,history

    s = 0
    for i in range(0,len(x)):
        s += int(toBase(int(x[i]),10)) * int(toBase(int(x[i]),10))
    if s in history:
        return False
        
    history.append(s)
    if s == 1:
        return True
    return calc(str(toBase(s,base)))




fin = open(f_name + '.in',"r")
fout = open(f_name + '.out',"w")

c = 0
num = int(fin.readline())
line = fin.readline()[:-1]
while c < num:
    #print '-------------------------'
    bs = line.split()
    #print bs
    i = 2
    happy = False
    
    while happy == False:
        happy = True
        for j in bs:
            history = []
            base = int(j)
            happy = calc(toBase(i,int(j)))
            if happy == False : break
        if happy ==True:
            fout.write("Case #" + str(c+1) + ": " + str(i) + "\n")
            print i
            break
        i += 1
        
            
        
        
    line = fin.readline()[:-1]
    c+=1


fin.close()
fout.close()
