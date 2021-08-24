import codejam

def base10toN(num,n):
    """Change a  to a base-n number.
    Up to base-36 is supported without special notation."""
    num_rep={10:'a',
         11:'b',
         12:'c',
         13:'d',
         14:'e',
         15:'f',
         16:'g',
         17:'h',
         18:'i',
         19:'j',
         20:'k',
         21:'l',
         22:'m',
         23:'n',
         24:'o',
         25:'p',
         26:'q',
         27:'r',
         28:'s',
         29:'t',
         30:'u',
         31:'v',
         32:'w',
         33:'x',
         34:'y',
         35:'z'}
    new_num_string=''
    current=num
    while current!=0:
        remainder = current % n
        if 36>remainder>9:
            remainder_string=num_rep[remainder]
        elif remainder>=36:
            remainder_string='('+str(remainder)+')'
        else:
            remainder_string=str(remainder)
        new_num_string=remainder_string+new_num_string
        current=current/n
    return new_num_string


class Solution(codejam.Solver):

    __gcache = {}
    def getnum(self, base, num, j=0):
        key = "%s_%s" % (base, num)
        if num in self._cache: return -1
        if key in self.__gcache: return self.__gcache[key]

        total = 0
        for i in num:
            total += int(i) ** 2

        total = base10toN(total, base)
        if total != '1':
            self._cache[num] = total
            res = self.getnum(base, total, j+1)
            self.__gcache[key] = res
            return res
    
        return total

    def solve(self, pset):
        pset = map(int, pset[0].split(' '))
        count = 1
        while True:
            count += 1
            self._cache = {}
            for base in pset:
                if self.getnum(base, base10toN(count, base)) != '1':
                    break
            else:
                break

        return str(count)
        

if __name__ == '__main__':
    cj = codejam.Problem(solver=Solution)
    cj.solve()
