################## Elena Khusainova #####################

################## Libraries ############################


######################### Main ##########################
filename = "A-large.in"

f = open(filename, "r")
data = f.read()
f.close()

data = data.split("\n")


T = data[0]
data.remove(T)
del data[-1]

for i in range(len(data)):
    temp = list(data[i])
    first = temp[0]
    answer = [temp[0]]
    for j in range(1,len(temp)):
        if temp[j] >= first:
            answer.insert(0,temp[j])
            first = temp[j]
        else:
            answer.append(temp[j])
        
    with open("Problem1Large_out.txt", "a") as myfile:
        myfile.write('Case #'+str(i+1)+': '+''.join(answer)+'\n')
    myfile.close()

        

