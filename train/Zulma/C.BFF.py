def happy_kids(l,N):
    l = [li - 1 for li in l]
    pos = [0]
    happy = 0
    last_index = -1
    index = 0
    counted = False
    while len(pos) < N:
        BFF = l[index]

        if BFF in pos:
            if pos[-2] == BFF:
                happy = happy + 1
                counted = True
            if last_index == -1:
                last_index = 1
            while last_index in pos:
                last_index = last_index + 1
            pos.append(last_index)
            #index = l[last_index]
            index = last_index
        else:
            if not counted:
                happy = happy + 1
            pos.append(BFF)
            #index = l[BFF]
            index = BFF
            last_index = -1
            counted = False

    BFF_end = l[-1]
    if BFF_end == 0:
        happy = happy + 1
    return happy

if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        N = int(raw_input())
        l = [int(x) for x in raw_input().split()]
        happy = happy_kids(l,N)
        print "Case #{}: {}".format(t+1, happy)
