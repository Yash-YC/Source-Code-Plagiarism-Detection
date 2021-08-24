import sys

def memoize(f):
    mem_dict = {}
    def wrapper(*args):
        args_tuple = tuple(args)
        if args_tuple not in mem_dict:
            result = f(*args)
            mem_dict[args_tuple] = result
        return mem_dict[args_tuple]
    wrapper.forget = lambda: mem_dict.clear()
    return wrapper

def get_sum_squares_digits(candidate, base):
    cand_digits = []
    while candidate > 0:
        cand_digits.append(candidate % base)
        candidate /= base
    return sum(d * d for d in cand_digits)

def is_happy(candidate, base):
    already_seen = set()
    def rec_is_happy(candidate, base):
        if candidate in already_seen:
            return False
        already_seen.add(candidate)
        sum_sq_dig = get_sum_squares_digits(candidate, base)
        if sum_sq_dig == 1:
            return True
        else:
            return rec_is_happy(sum_sq_dig, base)
    return rec_is_happy(candidate, base)

def is_happy_in_bases(candidate, bases):
    for base in bases:
        if not is_happy(candidate, base):
            return False
    return True

def solve_case(in_fp):
    bases = map(int, in_fp.readline().split())
    candidate = 2
    while True:
        if is_happy_in_bases(candidate, bases):
            return str(candidate)
        else:
            candidate += 1

def main(argv):
    sys.setrecursionlimit(100000)
    
    in_fp = open(argv[1], 'rb')
    out_fp = open(argv[2], 'wb')

    num_cases = int(in_fp.readline())
    for i in range(num_cases):
        solution = solve_case(in_fp)
        out_fp.write('Case #%d: %s\n' % (i+1, solution))
    
    in_fp.close()
    out_fp.close()

if __name__ == '__main__':
    main(sys.argv)
