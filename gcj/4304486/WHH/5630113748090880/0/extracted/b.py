infile = open("B-small-attempt1.in", "r")
outfile = open("B-small.out", "w")

t = int(infile.readline())
print(t)
casenumber = 1
for i in range(t):
    n = int(infile.readline())
    
    missing = []
    line_list = []
    for i in range(n*2-1):
        line = infile.readline()[:-1].split()
        
        for j in range(len(line)):
            line_list.append(int(line[j]))
            
    line_list = sorted(line_list)
    
    
    index = 0
    while index+1 < 2*n**2-n:
        if line_list[index] != line_list[index+1]:
            missing.append(line_list[index])
            index+=1
        else:
            index+=2
    if line_list[len(line_list)-2]!=line_list[len(line_list)-1]:
        missing.append(line_list[len(line_list)-1])
    missing.sort()
            
    print("Case #{}: ".format(casenumber), end='', file=outfile)
    for i in range(len(missing)):
        print(missing[i], end=' ', file=outfile)
    print('', file=outfile)
    casenumber+=1

infile.close()
outfile.close()
print("done")
