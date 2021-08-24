import sys
f = open(sys.argv[1], "r")
f_out = open("out.out", 'w')

print sys.argv[1]
n_tests = int(f.readline())


def problem_a(l):
    ans = []
    i = 0
    len = l.__len__()
    last = first = ord(l[0])
    #print (len, l)
    while i < len:
        let = ord(l[i])
        if let < last and let > first:
            print(let, last, first)
            return l
        if let >= first:
            ans.insert(0, l[i])
            first = let

        else:
            ans.append(l[i])
            last = let
        #rint (let, l[i])
        i += 1
    return ''.join(ans)

t = 1
while t <= n_tests:
    line = f.readline()

    res = problem_a(line.rsplit("\n")[0])
    print res
    f_out.write("Case #" + str(t) + ": " + res + "\n")
    t += 1

