happy_lookup = [{} for i in range(11)]  # happy_lookup[base][num] = True or False

def trans_base(input, original_base, target_base):
    num_10base = 0
    if original_base == 10:
        num_10base = int(input)
    elif 2 <= original_base < 10:
        for i in len(input):
            num_10base += int(input[i]) * (target_base ** (len(input) - i - 1))
    else:
        num_10base = 0
    
    output = ""
    remainder = 0
    quotient = num_10base
    while quotient > 0:
        remainder = quotient % target_base
        quotient = quotient / target_base
        output = str(remainder) + output
    return output

def repeat_happy(input_10base, target_base):
    repeat_num = trans_base(input_10base, 10, target_base)
    happy_result = 0
    for digit in repeat_num:
        happy_result += int(digit) * int(digit)
    return happy_result
    
def ishappy(input_10base, target_base):
    global happy_lookup
    happy_dict = happy_lookup[target_base]
    try_cache = []
    try_num = int(input_10base)
    bHappy = False
    while try_num not in try_cache:
        try_cache.append(try_num)
        if happy_dict.has_key(try_num):
            bHappy = happy_dict[try_num]
        else:
            try_num = repeat_happy(str(try_num), target_base)
            if try_num == 1:
                bHappy = True
    for num in try_cache:
        happy_dict[num] = bHappy
    return bHappy

def main():
    for case in range(input()):
        bases = map(int, raw_input().split())
        min_happy_num = 2
        while True:
            bAllHappy = True
            for target_base in bases:
                if not ishappy(str(min_happy_num), target_base):
                    bAllHappy = False
                    break
            if bAllHappy:
                break
            min_happy_num += 1
        
        print "Case #%d: %d" % (case + 1, min_happy_num)
        
main()
