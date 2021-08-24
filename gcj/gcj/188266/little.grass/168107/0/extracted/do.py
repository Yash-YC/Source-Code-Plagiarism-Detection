import sys
from happy import find_smallest

fdin = open(sys.argv[1],'r')
fdout = open(sys.argv[2],'w')

n = int(fdin.readline().strip())
for i in range(n):
    fdout.write('Case #%d: %d\n' % ((i+1),find_smallest(fdin.readline())))

fdin.close()
fdout.close()
