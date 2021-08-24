file = open("c:/CodeJam/problemB/B-large.in")
line = file.next()

## Number of Test Cases:  1<=T<=100
T=int(line)

## Tests each case
for testcase in range(T):
    N =file.next().split()
    STRIPS=[]
    for n in range(2*int(N[0])-1):
        S= file.next().split()
        STRIPS=STRIPS+S
    striplist=[]
    finallist=[]
    STRIPS.sort()
    for each in STRIPS:
        if each not in striplist:
            striplist.append(each)
            if STRIPS.count(each)%2==1:
                finallist.append(int(each))
    finallist.sort()
    print('Case #{}:'.format(testcase+1)), "".join([str(x)+" " for x in finallist] )
           
        
        
        
    

    
    

