import sys
from random import randint

def memoize(func):
    results = {}
    def wrapper(*args):
        if args not in results:
            results[args] = func(*args)
        return results[args]
    return wrapper

def sample(C, N):
    boosters = 1
    left = C - N
    while left > 1:
        boosters += 1
	for n in xrange(N):
            left -= (randint(1, C-n) <= left)
    if left == 1:
        chance_of_missing = 1.0
	for n in xrange(N):
            chance_of_missing *= 1.0 - (1.0 / (C-n))
	chance_of_getting_last = 1.0 - chance_of_missing
	boosters += 1.0 / chance_of_getting_last
    return boosters

def expected_to_get_all(C, N):
    samples = 100000
    return sum(sample(C, N) for _ in xrange(samples)) / float(samples)


def do_one_test_case(file):
    s = file.readline().strip()
    C, N = (int(b) for b in s.split())
    return expected_to_get_all(C, N)

def main(argv):
    f = open(argv[1], 'r')
    cases = int(f.readline().strip())
    sys.stderr.write('Cases: %d\n' % cases)
    output_list = []
    for i in xrange(cases):
        output_list.append('Case #%d: %s\n' % (i+1, do_one_test_case(f)))
        sys.stderr.write('%d of %d done\n' % (i+1, cases))
    f.close()
    if len(argv) > 2:
        expected_f = open(argv[2], 'r')
        expected_list = expected_f.readlines()
        expected_list = [line.strip()+'\n' for line in expected_list[0:-1]]
        if (output_list == expected_list):
            print 'Everything matched!'
        else:
            print 'Actual: %s' % output_list
            print 'Expected: %s' % expected_list
    else:
        print ''.join(output_list)

def test():
    print 'Usage: scriptname.py infile [outfile]'
    print 'I\'ll run the doctests instead!'
    import doctest
    doctest.testmod()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        test()
    else:
        main(sys.argv)
