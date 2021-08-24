import os

foldername = os.getcwd()
filename = "B-large"
f_i = open(os.path.join(foldername, filename+".in"))
T = int(f_i.readline())

if os.path.isfile(filename+".out"):
    os.remove(filename+".out")
f_o = open(filename+".out", 'w')

for case in range(T):
    N = int(f_i.readline())
    F = []
    for _ in range(2*N-1):
        F.extend(map(int,f_i.readline().split()))
    F.sort()
    S = set(F)
    ans = []
    for height in S:
        if F.count(height)%2:
            ans.append(height)
    ans.sort()
    
    f_o.write("Case #{}: ".format(case+1))
    f_o.write(' '.join(map(str,ans)))
    f_o.write('\n')

f_i.close()
f_o.close()