v = [];
def find_ans(N):
    for i in v:
        num = int(baseN(N,i))
        if not check(num,i):
            return False
    return True

def baseN(num,b):
  return ((num == 0) and  "0" ) or ( baseN(num // b, b).lstrip("0") + "0123456789abcdefghijklmnopqrstuvwxyz"[num % b])

def check(num,base):
    ch = {}
    while str(num) != '1':
        ans = 0
        for i in str(num):
            ans+=int(i)*int(i)
        num = int(baseN(ans,base))
        if num in ch:
            return False
        ch[num] = True
    return True

if __name__ == "__main__":
    fdin = open("fdin.txt","r")
    content = fdin.read()
    content = content.split('\n')
    case = 1
    for i in content[1:]:
        s = i.split(' ')
        v = []
        for k in s:
            v.append(int(k))
        num = 2;
        while not find_ans(num):
            num = num+1
        print 'Case #' + str(case) + ': ' + str(num)
        case = case + 1
            
