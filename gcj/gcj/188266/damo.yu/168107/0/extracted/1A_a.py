def get_base(n, base):
    number = list()
    while n >= base:
        number.append(str(n%base))
        n = n / base
    number.append(str(n))
    number.reverse()
    tmp = ''.join(number)
    return(int(tmp))

def square_sum(n, base):
    s = 0
    for i in str(n):
        i = int(i)
        s += i*i
        
    return(get_base(s, base))
    
    
def happy(n, base):
    tested = set()
    n = get_base(n, base)
    tested.add(n)
    t = n
    while True:
        t = square_sum(t, base)
        if t==1:
            return True
        if t in tested:
            return False
        
        tested.add(t)
        

def find_small(bases):
    n = 2
    last = int(bases[-1])
    while True:
        
        for base in bases:
            base = int(base)
            test = happy(n, base)
            if test==False:
                break
            
            if test==True and base==last:
                return(n)
            
        n += 1
        
        
        
def main(filename, result='result.txt'):
    rfile = open(filename)
    rfile.readline()
    case = 1
    wfile = open(result, 'w')
    for line in rfile:
        bases = line.strip().split()
        n = find_small(bases)
        wfile.write('Case #'+str(case)+': '+str(n)+'\n')
        case += 1
        
        
if __name__ == '__main__':
    import sys
    in_file = sys.argv[1]
    
    main(in_file)
    
    
    
    
    
    