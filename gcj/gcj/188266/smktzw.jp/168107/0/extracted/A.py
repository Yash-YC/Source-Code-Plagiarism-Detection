def num2list(num, base):
    i = 0
    while num >= base ** i: i += 1
    i -= 1
    ans = [0] * (i + 1)
    for d in range(i + 1):
        ans[d] = num // base ** (i - d)
        num -= ans[d] * (base ** (i - d))
    return ans

def check(num, base):
    num0 = num
    l = [0] * 3 # dummy
    l_set = set([])
    while num != 1:
        l = num2list(num, base)
        #print l, base, num0
        num = sum([_ ** 2 for _ in l])
        str_l = ''.join([str(_) for _ in l])
        if str_l in l_set:
            return False
        else:
            l_set.add(str_l)
    return True

def solve(input):
    input = [int(_) for _ in input.strip().split()]
    flag = True
    num = 1
    while flag:
        num += 1
        #print num, input
        for base in input:
            if not check(num, base):
                break
        else:
            return str(num)


if __name__ == '__main__':
    str_in = 'A-small-attempt0.in'

    f_out = open(str_in.rstrip('.in') + '.out', 'w')

    for i, input in enumerate(open(str_in)):
        input = input.strip()
        if i == 0:
            continue

        f_out.write('Case #' + str(i) + ': ' + solve(input) + '\n')
        print i

    f_out.close()
