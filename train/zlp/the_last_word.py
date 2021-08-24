
with open("test.txt", 'r') as f_in:
    T = int(f_in.readline().strip())
    output = ""
    for i in range(1, T + 1):
        s = f_in.readline().strip()
        res_str = ""
        for m in s:
            if len(res_str) > 0 and ord(m) >= ord(res_str[0]):
                res_str = m + res_str
            else:
                res_str = res_str + m
        output += "Case #{}: {}\n".format(i, res_str)
    f_out = open("output.txt", 'w')
    f_out.write(output)
    f_out.close()
