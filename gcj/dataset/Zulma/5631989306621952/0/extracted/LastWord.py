
def add_letter(word, letter):
    if word + letter > letter + word:
        return word + letter
    else:
        return letter + word


if __name__ == '__main__':
    T = int(raw_input())
    index = 1
    for _ in range(T):
        letters = raw_input()
        word = ""
        for l in letters:
            word = add_letter(word, l)
        print "Case #{}: {}".format(index, word)
        index = index + 1
