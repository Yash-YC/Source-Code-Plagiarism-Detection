def reader(inFile):
    return tuple(inFile.getInts())

fc = [1]
for i in xrange(1,21):
    fc.append(fc[-1] * i)

def combin(n,k):
    return fc[n]/(fc[k]*fc[n-k])

def g2(n):
    return sum([combin(n-1,p-1)*combin(n,p)*fc[p]*fc[p-1]*g(n-p) for p in xrange(2,n+1)])

gc = {0:1,1:0,2:2}
def g(z):
    if z not in gc:
        gc[z] = g2(z)
    return gc[z]

def f(N,i):
    return combin(N,i)*combin(N,i)*fc[i]*g(N-i)

def solver((N,X)):
    return sum(f(N,i) for i in xrange(X,N+1)) % (10 ** 9 + 7)

if __name__ == "__main__":
    # GCJ library publically available at http://ideone.com/2PcmZT
    from GCJ import GCJ
    GCJ(reader, solver, r"C:\gcj\finals\b", "b").run()
    print gc

