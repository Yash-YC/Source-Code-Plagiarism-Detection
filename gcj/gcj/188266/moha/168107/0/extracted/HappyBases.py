import sys
from copy import copy
 
f = open('data/A-small-attempt1.in', 'r')
o = open('data/A-small-attempt1.out', 'w')

t = f.readline().strip();

def convert_base(num, n):
    new_num_string=''
    current=num
    while current!=0:
        remainder=current%n
        
        remainder_string=str(remainder)
        
        new_num_string=remainder_string+new_num_string
        
        current=current/n
        
    return new_num_string

def happiness(_num, _base):
    if unhappy[_base].has_key(_num) and unhappy[_base][_num]:
        return False
    
    nnum=0
    for c in str(_num):
        nnum+=int(c)*int(c)
    
    nnum = convert_base(nnum, int(_base))
    
    if int(nnum) != 1:
        try:
            return happiness(nnum, _base)
        except RuntimeError:
            unhappy[_base][nnum] = True
            return False
    else:
        return True
    return False

for i in range(int(t)):    
    _bases = f.readline().strip().split(' ');
    
    number = 2
    unhappy = {}
    
    for base in _bases:
        unhappy[int(base)] = {}
    
    while True:
        happy = True
        for base in _bases:
            if int(base) == 2:
                continue
            num = convert_base(number, int(base))
            if not happiness(num, int(base)):
                happy = False
                break
            
        if happy:
            o.write("Case #" + str(i+1) + ": " + str(number) + "\n")
            break
        
        number+=1
        
    print i
        
        
        