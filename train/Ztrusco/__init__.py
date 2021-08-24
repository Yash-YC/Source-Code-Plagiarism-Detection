import fileinput

def main():

    for i, line in enumerate(fileinput.input()):
        if i == 0:
            continue
        print("Case #" + str(i) + ": " + lastWord(line.replace("\n", "")))


def lastWord(word):
    w = word[0]

    list = generate(word, w)

    l = sorted(list, key=str.lower, reverse=True)
    return l[0]


def generate(word, w):

    if len(word) == len(w):
        return [w]

    w1 = w
    w4 = w

    w1 = word[len(w)] + w1
    w4 = w4 + word[len(w)]

    return generate(word, w1) + generate(word, w4)

if __name__ == "__main__":
    main()
