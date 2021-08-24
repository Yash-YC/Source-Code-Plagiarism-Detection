import pprint

if __name__ == "__main__":
    fin  = open('d:\\a.in', 'r')
    fout = open('d:\\a.out', 'w')
    T = int(fin.readline())
    solve = {}
    
    def check(i, b):
        #print('%d %d' % (i, b))
        a = []
        while i != 1:
            k = i
            s = 0
            while k >= b:
                c = k % b
                s += c * c
                k = k // b
            s += k * k
            #print('>>%d' % s)
            if s in a:
                return False
            a.append(s)
            i = s
        return True
    
    for l in range(1, T+1):
        print('Line %d' % l)
        line = fin.readline().split()
        ar = []
        for i in range(len(line)):
            ar.append(int(line[i]))
        pprint.pprint(ar)
        for i in range(2, 4294967295):
            valid = True
            for b in ar:
                #print('b %d' % b)
                if b == 2: continue
                x = solve.get(b)
                if (x == None):
                    solve[b] = {}
                    x = solve.get(b)
                y = x.get(i)
                if (y == None):
                    x[i] = check(i, b)
                    y = x.get(i)
                #if i == 27: break
                if not y:
                    valid = False
                    break
            if (valid):
                fout.write('Case #%d: %d\n' % (l, i))
                break
    #pprint.pprint(solve)
