def processFile(a):
    with open(a, 'r') as r:
              fileobj = r.readlines()
    new_list = []
    new_list1 = []
    for item in fileobj:
        parse = item.rstrip().split(" ")
        for item1 in parse:
           new_list.append(item1.rsplit(","))
    return new_list

def markSweep(input):
    n = int(input[0][0])
    possiblelist = []
    for index in range(n):
        possiblelist.append(str(index)) #All possible heapblocks
    input.pop(0)
    thisdict = {}
    for i in range(len(input)):
        if input[i][0] in thisdict:
            thisdict[input[i][0]].append(input[i][1])
        else:
            thisdict[input[i][0]] = [input[i][1]]

    print(thisdict)
    charlist = [] #List of pointerblocks
    for i in range(len(input)):
        if input[i][0].isalpha():
            charlist.append(input[i][0])
    markednodes = []
    sweptnodes = []




    for item in charlist:
        key = item
        while key in thisdict:
            key = thisdict[key][0]
            if key not in markednodes:
                markednodes.append(key)




    print("Marked Nodes:",sorted(markednodes))
    print ("Swept Nodes:",sorted(set(possiblelist) - set(markednodes)))


list = processFile("sample.txt")
markSweep(list)