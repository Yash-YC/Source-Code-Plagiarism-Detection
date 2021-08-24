#! /usr/bin/env python


def build_biggest(letters):
    biggest, letters = letters[0], letters[1:]
    for letter in letters:
        if letter >= biggest[0]:
            biggest = letter + biggest
        else:
            biggest = biggest + letter
    return biggest

T = int(raw_input())
for case in range(T):
    S = raw_input()
    answer = build_biggest(S)
    print 'Case #{}: {}'.format(case + 1, answer)
