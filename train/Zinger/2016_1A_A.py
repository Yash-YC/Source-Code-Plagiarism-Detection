import os

foldername = os.getcwd()
filename = "A-large"
f_i = open(os.path.join(foldername, filename+".in"))
T = int(f_i.readline())

if os.path.isfile(filename+".out"):
    os.remove(filename+".out")
f_o = open(filename+".out", 'w')

def doit(S):
    if S == '':
        return ''
    else:
        high = len(S)-S[::-1].find(max(S))-1
        S = S[high]+doit(S[:high])+S[high+1:]
        return S

for case in range(T):
    S = f_i.readline().strip()
    S = doit(S)

    f_o.write("Case #{}: {}\n".format(case+1,S))

f_i.close()
f_o.close()