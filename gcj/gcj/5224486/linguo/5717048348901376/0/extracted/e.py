def reader(inFile):
    (N,M) = tuple(inFile.getInts())
    spells = [tuple(inFile.getInts()) for j in xrange(N)]
    return (N,M,spells)

from fractions import gcd

def f(spells):
    score = 0
    for z in spells:
        score += max([0,z[0],z[0]+z[1]])
    return score

def solver((N,M,spells)):
    spells = [z for z in spells if max(z) > 0]
    if len(spells) == 0:
        return 0
    if M == 1:
        return sum(z[0] for z in spells)
    return max(f(spells),f([(z[1],z[0]) for z in spells]))

if __name__ == "__main__":
    # GCJ library publically available at http://ideone.com/2PcmZT
    from GCJ import GCJ
    GCJ(reader, solver, r"C:\gcj\finals\e", "e").run()
