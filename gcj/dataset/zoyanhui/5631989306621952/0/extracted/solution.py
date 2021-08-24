def print_case_result(case_num, result):
    print "Case #" + str(case_num) +": " + str(result)


def find_max(origin_str):
    ret = []
    # sorted_str = sorted([x for x in origin_str], reverse=True)
    max_stack = []
    # cur = 0
    for s in origin_str:
        if not max_stack or max_stack[-1] <= s:
            max_stack.append(s)
        else:
            ret.append(s)
    return list(reversed(max_stack)) + ret 





if __name__ == '__main__':
    testcase_num = int(raw_input())
    for case_num in range(1, testcase_num+1):
        origin_str = raw_input().strip()
        result_str = ''.join(find_max(origin_str))
        print_case_result(case_num, result_str)
1