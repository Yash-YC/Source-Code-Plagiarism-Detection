import sys

def memoize(func):
    results = {}
    def wrapper(*args):
        if args not in results:
            results[args] = func(*args)
        return results[args]
    return wrapper

def is_happy(n, b):
    """
    >>> is_happy(82, 10)
    True
    >>> is_happy(1, 10)
    True
    >>> is_happy(2, 10)
    False
    >>> is_happy(143, 2)
    True
    >>> is_happy(143, 3)
    True
    >>> is_happy(143, 7)
    True
    """
    has_seen = set()
    @memoize
    def _is_happy(n, b):
        if n in has_seen:
            return False
        s = "%d" % n
        if s == '1':
            return True
        has_seen.add(n)
        next = 0
	while n > 0:
            n, r = divmod(n, b)
            next += r * r
        return _is_happy(next, b)
    return _is_happy(n, b)

def happy_in_bases(n, bases):
    for b in bases:
        if not is_happy(n, b):
            return False
    return True

def do_one_test_case(file):
    s = file.readline().strip()
    bases = list(int(b) for b in s.split())
    n = 2
    while True:
	if happy_in_bases(n, bases):
            return n
        n += 1

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
