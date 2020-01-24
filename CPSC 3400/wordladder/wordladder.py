def readfile(wordfile):
    MAX = 6
    MIN = 4
    wordfile = wordfile
    wordlist = []
    file = open(wordfile, "r")
    for line in file:
        str = line.strip()
        if MIN <= len(str) and len(str) <= MAX:
            wordlist.append(str)
    return wordlist


def process(pairfile, wordlist):
    file = open(pairfile, "r")
    for line in file:
        word = line.split()
        if len(word[0]) == len(word[1]):
            startingword = word[0]
            finalword = word[1]


def main():
    wordlist = readfile("words.txt")
    print(wordlist)
    process("pairs.txt", wordlist)


if __name__ == '__main__':
    main();
