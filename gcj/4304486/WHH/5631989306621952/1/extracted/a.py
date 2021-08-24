infile = open("A-large.in", "r")
outfile = open("A-large.out", "w")

t = infile.readline()
print(t)
casenumber = 1
for line in infile:
    print(line)
    s = list(line[:-1])
    output = ['' for x in range(len(s))]
    for i in range(len(s)):
        if i == 0:
            output[0] = s[0]
        elif s[i] < output[0]:
            output[i] = s[i]
        else:
            for j in range(len(output)-1, -1, -1):
                if output[0] == '':
                    break
                output[j] = output[j-1]
            output[0] = s[i]
    print("Case #{}: ".format(casenumber), end='', file=outfile)
    for i in range(len(output)):
        print(output[i], end='', file=outfile)
    print('', file=outfile)
    casenumber+=1
        
print("done")
infile.close()
outfile.close()
