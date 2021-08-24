#! /usr/bin/env python

def all_words(letters, built=None):
    if built is None:
        built = set([''])
    if not letters:
        return built
    first, rest = letters[0], letters[1:]
    built = set(first + b for b in built) | set(b + first for b in built)
    return all_words(rest, built)

T = int(raw_input())
for case in range(T):
    S = raw_input()
    answer = sorted(all_words(S))[-1]
    print 'Case #{}: {}'.format(case + 1, answer)
