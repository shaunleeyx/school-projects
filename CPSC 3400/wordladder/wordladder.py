import queue
import time
#bounds
MAX = 6
MIN = 4


def readfile(wordfile):
    wordfile = wordfile
    wordset = dict()
    file = open(wordfile, "r")
    # every single combination for missing char dictionary from the wordfile line by line
    for line in file:
        str = line.strip()
        if MIN <= len(str) and len(str) <= MAX:
            for i in range(len(str)):
                string = str[:i] + '-' + str[i+1:]
                wordset.setdefault(string, []).append(str)

# makes dictionary with every single combination with duplicates
    worddict = dict()
    for key in wordset:
        for item1 in wordset[key]:
            for item2 in wordset[key]:
                if item1 != item2:
                    worddict.setdefault(item1, []).append(item2)
                    worddict.setdefault(item2, []).append(item1)

    # remove duplicates
    for item in worddict:
        worddict[item] = list(dict.fromkeys(worddict[item]))

    return worddict


def process(pairfile, wordlist):
    file = open(pairfile, "r")
    for line in file:
        word = line.split()
        startingword = word[0]
        endingword = word[1]
        print("Looking for ladder from " + startingword + " to " + endingword)
        if len(startingword) == len(endingword) and len(startingword) >= MIN and len(startingword) <= MAX and len(endingword) >= MIN and len(endingword) <= MAX and startingword in wordlist:
            start_time = time.time()
            print(bfs(startingword, endingword, wordlist))
            print("Elapsed time =", time.time() - start_time)
            print()
        else:
            print("not the same length or it is out of bounds or startingword is not in wordlist")
            print("Elapsed time =", time.time() - start_time)
            print()


def bfs(start, end, wordlist):
    bfsq = queue.Queue()
    initialList = [start]
    marked = []
    bfsq.put(initialList)
    marked.append(start)
    while not bfsq.empty():
        pop = bfsq.get()
        lastword = pop[-1]
        for item in wordlist[lastword]:
            if item not in marked:
                if item == end:
                    pop.append(item)
                    return pop
                marked.append(item)
                temp = pop.copy()
                temp.append(item)
                bfsq.put(temp)
    return ("no ladder found from " + start + "  to " + end)
        


                



def main():
    wordlist = readfile("words.txt")
    process("pairs.txt",wordlist)


if __name__ == '__main__':
    main()
