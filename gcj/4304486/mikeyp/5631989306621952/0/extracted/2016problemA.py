file = open("c:/CodeJam/problemA/A-small-attempt0.in")
line = file.next()

## Number of Test Cases:  1<=T<=100
T=int(line)

## Tests each case
for testcase in range(T):
    S = file.next().split()
    LW=[]
    for each in S[0]:
        if not LW:
            LW.append(each)
        else:
            if each>=LW[0]:
                LW.insert(0,each)
            else:
                LW.append(each)


    LASTWORD=''

    for each in LW:
        LASTWORD=LASTWORD+each

    print('Case #{}: {}'.format(testcase+1,LASTWORD))
           
        
        
        
    

    
    

