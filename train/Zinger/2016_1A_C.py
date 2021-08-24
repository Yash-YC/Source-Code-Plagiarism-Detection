import os

foldername = os.getcwd()
filename = "C-small-attempt2"
f_i = open(os.path.join(foldername, filename+".in"))
T = int(f_i.readline())

if os.path.isfile(filename+".out"):
    os.remove(filename+".out")
f_o = open(filename+".out", 'w')

for case in range(T):
    N = int(f_i.readline())
    F = map(int,f_i.readline().split())
    F[:] = [i-1 for i in F]

    possible = []
    buddy = []
    pairs = set()
    for i, _ in enumerate(F):
        circle = [i]
        BFF = F[i]
        while BFF not in circle:
            circle.append(BFF)
            BFF = F[BFF]
        if circle[0] == BFF:
            possible.append(circle)
        elif circle[-2] == BFF:
            possible.append(circle)
            buddy.append(circle)
            pairs.add(tuple(circle[-2:]))
        else:
            circle = circle[circle.index(BFF):]
            possible.append(circle)
    
    dubs = 0
    for pair in pairs:
        if tuple(list(pair)[::-1]) in pairs:
            left = []
            right = []
            for bud in buddy:
                if bud[-2:] == list(pair):
                    left.append(len(bud)-1)
                if bud[-2:] == list(pair)[::-1]:
                    right.append(len(bud)-1)
            dubs = max(max(left) + max(right),dubs)

    ans = len(max(possible,key=len))
    if dubs:
        ans = max(ans,dubs)

    f_o.write("Case #{}: {}\n".format(case+1,ans))

f_i.close()
f_o.close()