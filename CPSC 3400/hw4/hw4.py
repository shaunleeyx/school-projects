import sys
from functools import reduce

list = []

class InvalidFile(Exception):pass
def createFractionList(a):
    with open(a, 'r') as r:
              fileobj = r.readlines()
    new_list = []

    for item in fileobj:

        a = item.split()[0]
        b = item.split()[1]
        if not a.lstrip("-").isdigit() or not b.isdigit() or len(item.split()) > 2 or int(b) <= 0:
            raise InvalidFile('InvalidFile')
        int_list = [int(i) for i in item.split()]
        new_list.append(tuple(int_list))
    return new_list

def simplify(fraction):
    list1 = []
    if fraction[0] == 0:
        return (0,1)
    for i in range(1, fraction[1]+1):
        if(fraction[0] % i == 0 and fraction[1] % i == 0):
            list1.append(i)
        tuple = (round(fraction[0]/max(list1)),round((fraction[1]/max(list1))))
    return tuple



def genDifferences(fractionList, target):
            for i in range(0,len(fractionList)):
                GCD = target[1]*fractionList[i][1]
                if fractionList[i][0] != 0:
                    result = fractionList[i][0] * (GCD / fractionList[i][1])-target[0] * (GCD / target[1])
                    tup1 = (round(result),GCD)
                    yield simplify(tup1)
                else:
                    yield (-target[0],target[1])

###################### 11 STEPS ########################
try:
    target = (int(sys.argv[2]), int(sys.argv[3]))
    fractionList = createFractionList(sys.argv[1])
    print("step 3:",fractionList)
    my_list = [simplify(item) for item in fractionList]
    print("step 5:",my_list)
    print("step 6")
    for item in genDifferences(fractionList, target):
        print(item)
    print("step 7:",list(map((lambda x: x[0]/x[1]), fractionList)))
    print("step 8:",list(map(lambda x: simplify((x[0]*2,x[1])), fractionList)))
    print("step 9:",list(filter(lambda x: x[0]/x[1] > target[0]/target[1], fractionList)))
    print("step 10:",list(reduce(lambda x,y: y if x > y else x,fractionList)))
    print("step 11:",reduce(lambda x,y:simplify((x[0] * y[1] + y[0] * x[1], x[1]* y[1])),fractionList))
except InvalidFile:
    print("invalid file caught")
    sys.exit(InvalidFile)
except FileNotFoundError:
    print("FileNotFoundError caught")
    sys.exit(InvalidFile)


