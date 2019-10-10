import six
import sys
def isLeapYear(year):
    if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0) :
        return True
    else:
        return False

def improperExcept():
    raise Exception('ImproperDate')
    sys.exit(1)

def createDateList(fileName):
    with open(fileName, 'r') as r:
        fileobj = r.readlines()
        new_list = []
        dateList = []
        for item in fileobj:

            parse = item.rstrip().split(" ")
            if len(parse) != 3:
                raise Exception('BadFileFormat')
                sys.exit(1)
            #if int(parse[2]) < 1800 or (int(parse[1]) > 31 or int(parse[1]) < 1) or (int(parse[0]) > 12 or int(parse[0]) < 1) :
            if int(parse[2]) < 1800:
                improperExcept()
            if int(parse[0]) > 12:
                improperExcept()
            if int(parse[0]) == 1:
                if int(parse[1]) > 31 or int(parse[1]) < 1:
                    improperExcept()
            if int(parse[0]) == 2:
                if int(parse[1]) > 29 or int(parse[1]) < 1:
                    improperExcept()
                if int(parse[1]) == 29 and not isLeapYear(int(parse[2])):
                    improperExcept()
            if int(parse[0]) == 3:
                if int(parse[1]) > 31 or int(parse[1]) < 1:
                    improperExcept()
            if int(parse[0]) == 4:
                if int(parse[1]) > 30 or int(parse[1]) < 1:
                    improperExcept()
            if int(parse[0]) == 5:
                if int(parse[1]) > 31 or int(parse[1]) < 1:
                    improperExcept()
            if int(parse[0]) == 6:
                if int(parse[1]) > 30 or int(parse[1]) < 1:
                    improperExcept()
            if int(parse[0]) == 7:
                if int(parse[1]) > 31 or int(parse[1]) < 1:
                    improperExcept()
            if int(parse[0]) == 8:
                if int(parse[1]) > 31 or int(parse[1]) < 1:
                    improperExcept()
            if int(parse[0]) == 9:
                if int(parse[1]) > 30 or int(parse[1]) < 1:
                    improperExcept()
            if int(parse[0]) == 10:
                if int(parse[1]) > 31 or int(parse[1]) < 1:
                    improperExcept()
            if int(parse[0]) == 11:
                if int(parse[1]) > 30 or int(parse[1]) < 1:
                    improperExcept()
            if int(parse[0]) == 12:
                if int(parse[1]) > 31 or int(parse[1]) < 1:
                    improperExcept()
            new_list.append(parse)
        for date in new_list:
            for i in range(len(date)):
                month = int(date[0])
                day = int(date[1])
                year = int(date[2])
            dateList.append((month, day, year))
        return dateList

def genFinalDates(year):
    List = []
    List.append((1,31,year))
    if isLeapYear(year):
        List.append((2,29,year))
    else:
        List.append((2,28,year))
    List.append((3,31,year))
    List.append((4,30,year))
    List.append((5,31,year))
    List.append((6,30,year))
    List.append((7,31,year))
    List.append((8,31,year))
    List.append((9,30,year))
    List.append((10,31,year))
    List.append((11,30,year))
    List.append((12,31,year))
    return List


    
dateList = createDateList(sys.argv[1])
print("Step 4:")
for x in genFinalDates(dateList[0][2]):
    print(x)
print("Step 5:")
numofdays = 0
for x in genFinalDates(dateList[0][2]):
    numofdays = numofdays + (x[1])
print(numofdays)
print("Step 6:")
print(max(dateList))
print("Step 7:")
print(sorted(dateList, key=lambda x: x[2]))
print("Step 8:")
templist = []
for x in dateList:
    templist.append(x[2])
print(templist)
monthStr = ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"]
print("Step 10:")
finalList = []
for index in dateList:
    finalList.append(monthStr[index[0]-1] + " " + str(index[1]) + ", " + str(index[2]))


print(finalList)