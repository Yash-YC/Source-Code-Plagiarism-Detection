import sys

def baseconvert(number,tobase):
    res = []
    while number>0:
        res.append(str(number % tobase))
        number /= tobase
    return "".join(res)

def squaresum(number, base):
    return sum([int(n)*int(n) for n in baseconvert(number,base)])

def is_happy(number, base=10):
    results = []
    while number != 1:
        number = squaresum(number, base)
        if number in results:
            return False
        results.append(number)
    return True

def happy_in_all_bases(number, bases=[10]):
    return all(is_happy(number, base) for base in bases)

def first_happy_in_bases(bases):
    testnumber = 2
    while True:
        if happy_in_all_bases(testnumber, bases):
            return testnumber

        testnumber += 1

def solve_input(input):
    lines = [l.strip() for l in input.readlines()]
    num_tests = int(lines[0])
    result = ""
    for line in range(1,num_tests+1):
        result = "%sCase #%d: %d\n" % (result,
                                       line,
                                       first_happy_in_bases([int(n) for n in lines[line].split(" ")]))
    return result

if __name__ == "__main__":
    of = open("cj.out","w")
    of.write(solve_input(open(sys.argv[1],'r')))
    of.close()
