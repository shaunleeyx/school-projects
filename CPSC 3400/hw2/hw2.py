#'/Users/shaunlee/PycharmProjects/hw2/dates.txt'
def createDateList(Filename):
    with open(Filename, 'r') as r:
        fileobj = r.readlines()
    new_list = []
    for item in fileobj:
        parse = item.rstrip().split(" ")
        new_list.append(parse)

    return new_list



print(createDateList("/Users/shaunlee/PycharmProjects/hw2/dates.txt"))