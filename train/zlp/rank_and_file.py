
with open("test.txt", 'r') as f_in:
    T = int(f_in.readline().strip())
    output = ""
    for i in range(1, T + 1):
        counts = [0] * 2500
        N = int(f_in.readline().strip())
        for k in range(2 * N - 1):
            lst = [int(s) for s in f_in.readline().strip().split(' ')]
            for s in lst:
                counts[s - 1] += 1
        res_lst = []
        for k in range(len(counts)):
            if counts[k] % 2 != 0:
                res_lst.append(k + 1)
        res_lst.sort()
        res_str = "".join([" " + str(s) for s in res_lst])
        output += "Case #{}:{}\n".format(i, res_str)
    f_out = open("output.txt", 'w')
    f_out.write(output)
    f_out.close()
