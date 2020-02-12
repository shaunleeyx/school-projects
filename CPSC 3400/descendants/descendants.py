"""
GEDCOM parser design

Create empty dictionaries of individuals and families
Ask user for a file name and open the gedcom file
Read a line
Skip lines until a FAM or INDI tag is found
    Call functions to process those two types
Print descendant chart when all lines are processed

Processing an Individual
Get pointer string
Make dictionary entry for pointer with ref to Person object
Find name tag and identify parts (surname, given names, suffix)
Find FAMS and FAMC tags; store FAM references for later linkage
Skip other lines

Processing a family
Get pointer string
Make dictionary entry for pointer with ref to Family object
Find HUSB WIFE and CHIL tags
    Add included pointer to Family object
    [Not implemented ] Check for matching references in referenced Person object
        Note conflicting info if found.
Skip other lines

Print info from the collect of Person objects
Read in a person number
Print pedigree chart
"""


# -----------------------------------------------------------------------
import GEDtest
#stores info about events
class Event(): 

    def __init__(self):
            self._birth = ""
            self._death = None
            self._marriage = None
            self._divorce = None
            self._records = "" 
            self._gender = None
            self._edu = None

    def gender(self):
         return self.gender

    

    def addBirth(self,date = ''):
        self._birth = date
    
    def addDeath(self,date = ''):
        self._death = date
    
    def addMarriage(self,date = ''):
        self._marriage = date 

    def addDivorce(self,date = ''):
        self._divorce = date 

    def addRecords(self,note =''):
        self._records += [note]
    
    def addGender(self,gen =""):
        self._gender = gen 

    def addEdu(self,ed = ""):
        self._edu = ed
class Person():
    # Stores info about a single person
    # Created when an Individual (INDI) GEDCOM record is processed.
    # -------------------------------------------------------------------
    def __init__(self, ref):
        # Initializes a new Person object, storing the string (ref) by
        # which it can be referenced.
        self._id = ref
        self._asSpouse = []  # use a list to handle multiple families
        self._asChild = None
        self.eventObj = Event()

    def addBirth(self,date = ''):
        self.eventObj._birth = date
    
    def addDeath(self,date = ''):
        self.eventObj._death = date
    
    def addGender(self,gen =''):
        self.eventObj.addGender = gen

    def addRecords(self,note =''):
        self.eventObj._records.append(note)

    def addName(self, names):
        # Extracts name parts from a list of name and stores them
        self._given = names[0]
        self._surname = names[1]
        self._suffix = names[2]

    def addIsSpouse(self, famRef):
        # Adds the string (famRef) indicating family in which this person
        # is a spouse, to list of any other such families
        self._asSpouse += [famRef]

    def addIsChild(self, famRef):
        # Stores the string (famRef) indicating family in which this person
        # is a child
        self._asChild = famRef

    def printDescendants(self, prefix=''):
        # print info for this person and then call method in Family
        print(prefix + self.name())
        # recursion stops when self is not a spouse
        for fam in self._asSpouse:
            families[fam].printFamily(self._id, prefix)

    def name(self):
        # returns a simple name string
        return self._given + ' ' + self._surname.upper()\
            + ' ' + self._suffix

    def __str__(self):
        # returns a string representing all info in the Person instance
        if self._asChild:  # make sure value is not None
            childString = ' | asChild: ' + self._asChild
        else:
            childString = ''
        if self._asSpouse != []:  # make sure _asSpouse list is not empty
            # spouseString = ' asSpouse: ' + str(self._asSpouse)
            spouseString = ' | asSpouse: ' + ','.join(self._asSpouse)
        else:
            spouseString = ''
        return self._given + ' ' + self._surname.upper()\
            + ' ' + self._suffix \
            + childString + spouseString

    def isDescendantHelper(self, pObj, target=""):
        if pObj._id == target:
            return True
        elif target == "":
            return False
        elif len(pObj._asSpouse) > 0:
            for famID in pObj._asSpouse:
                for child in families[famID]._children:
                    p = persons[child]
                    if pObj.isDescendantHelper(p, target) == True:
                        return True
        return False

    def isDescendant(self, target=""):
        p = persons[self._id]
        if self.isDescendantHelper(p, target):
            return True
        return False

    def parentFamID(self):
        for item in families.items():
            if item[1]._husband == self._id or item[1]._wife == self._id:
                return item[0]
        for item in families.items():
            for kid in item[1]._children:
                if kid == self._id:
                    return item[0]

    def getFamilyId(self, str):
        for item in families.items():
            for x in item[1]._children:
                if x == str:
                    return item[0]

# function gets the family root of person object
    def getRoot(self):
        child = self._id
        while True:
            f = families[self.getFamilyId(child)]
            if f._husband != None:
                parent = f._husband
            elif f._wife != None:
                parent = f._wife
            if self.getFamilyId(parent) == None:
                return self.getFamilyId(child)
            child = parent
        f = families[self.getRoot()]

    #helps printAncestors()
    def printAncestorsHelper(self, pObj, string,count = 0):
        if pObj._asChild == None:
            print(string,count,pObj.name())
        else: 
            f = families[pObj._asChild]
            dad =persons[f._husband]
            mom =persons[f._wife]
            self.printAncestorsHelper(dad,string= string + " ",count= count + 1)
            self.printAncestorsHelper(mom,string= string + " ",count= count + 1)
            print(string,count,pObj.name())
        
    def printAncestors(self, string):
        self.printAncestorsHelper(self, string)


# famID = pObj.parentFamID()
#         if len(pObj._asSpouse) == 0: pass
#         else:
#             ws = ""
#             for x in range(count):
#                 ws = ws + " "
#             f = families[famID]
#             hus = persons[f._husband]
#             print(ws,count," ",hus.name())
#             for kidID in f._children:
#                 self.printAncestorsHelper(persons[kidID],count+1)
#             wife = persons[f._wife]
#             print(ws,count," ",wife.name())


# end of class person

# -----------------------------------------------------------------------

class family():
    # stores info about a family
    # created when an family (fam) gedcom record is processed.
    # -------------------------------------------------------------------

    def __init__(self, ref):
        # Initializes a new Family object, storing the string (ref) by
        # which it can be referenced.
        self._id = ref
        self._husband = None
        self._wife = None
        self._children = []

    def addHusband(self, personRef):
        # Stores the string (personRef) indicating the husband in this family
        self._husband = personRef

    def addWife(self, personRef):
        # Stores the string (personRef) indicating the wife in this family
        self._wife = personRef

    def addChild(self, personRef):
        # Adds the string (personRef) indicating a new child to the list
        self._children += [personRef]

    def getWife(self):
        return self._wife

    def getHusband(self):
        return self._husband

    def getChildren(self):
        return self._children

    def printFamily(self, firstSpouse, prefix):
        # Used by printDecendants in Person to print spouse
        # and recursively involve printDescendants on children
        if prefix != '':
            prefix = prefix[:-2]+'  '
        if self._husband == firstSpouse:
            if self._wife:  # make sure value is not None
                print(prefix + '+' + persons[self._wife].name())
        else:
            if self._husband:  # make sure value is not None
                print(prefix + '+' + persons[self._husband].name())
        for child in self._children:
            persons[child].printDescendants(prefix+'|--')

    def __str__(self):
        if self._husband:  # make sure value is not None
            husbString = ' Husband: ' + self._husband
        else:
            husbString = ''
        if self._wife:  # make sure value is not None
            wifeString = ' Wife: ' + self._wife
        else:
            wifeString = ''
        if self._children != []:
            childrenString = ' Children: ' + ','.join(self._children)
        else:
            childrenString = ''
        return husbString + wifeString + childrenString

# end of class Family

# -----------------------------------------------------------------------
# Global dictionaries used by Person and Family to map INDI and FAM identifier
# strings to corresponding object instances


persons = dict()  # saves references to all of the Person objects
families = dict()  # saves references to all of the Family objects

# -----------------------------------------------------------------------


def processGEDCOM(file):

    def getPointer(line):
        # A helper function used in multiple places in the next two functions
        # Depends on the syntax of pointers in certain GEDCOM elements
        # Returns the string of the pointer without surrounding '@'s or trailing
        return line[8:].split('@')[0]

    def processPerson(newPerson):
        nonlocal line
        line = f.readline()
        while line[0] != '0':  # process all lines until next 0-level
            # substring where tags are found in 0-level elements
            tag = line[2:6]
            # print(tag)
            if tag == 'NAME':
                names = line[6:].split('/')  # surname is surrounded by slashes
                names[0] = names[0].strip()
                names[2] = names[2].strip()
                newPerson.addName(names)
            elif tag == 'FAMS':
                newPerson.addIsSpouse(getPointer(line))
            elif tag == 'FAMC':
                newPerson.addIsChild(getPointer(line))
            # add code here to look for other fields
            elif tag == 'BIRT':
                line = f.readline()
                line = line[7:]
                print(line)
                newPerson.addBirth(line)
            elif tag == 'DEAT':
                a = line.split()
                if len(a) == 2:
                    line = f.readline()
                    line = line[7:]
                    newPerson.addDeath(line)
            elif tag.strip() == 'SEX':
                list = line.split()
                line = list[2]
                print(line)
                newPerson.addGender(line)
            # elif tag == "TIME":
            
            # read to go to next line
            line = f.readline()

    def processFamily(newFamily):
        nonlocal line
        line = f.readline()
        while line[0] != '0':  # process all lines until next 0-level
            tag = line[2:6]
            if tag == 'HUSB':
                newFamily.addHusband(getPointer(line))
            elif tag == 'WIFE':
                newFamily.addWife(getPointer(line))
            elif tag == 'CHIL':
                newFamily.addChild(getPointer(line))
            # add code here to look for other fields

            # read to go to next line
            line = f.readline()

    # f is the file handle for the GEDCOM file, visible to helper functions
    # line is the "current line" which may be changed by helper functions

    f = open(file)
    line = f.readline()
    while line != '':  # end loop when file is empty
        fields = line.strip().split(' ')
        # print(fields)
        if line[0] == '0' and len(fields) > 2:
            # print(fields)
            if (fields[2] == "INDI"):
                ref = fields[1].strip('@')
                # create a new Person and save it in mapping dictionary
                persons[ref] = Person(ref)
                # process remainder of the INDI record
                processPerson(persons[ref])

            elif (fields[2] == "FAM"):
                ref = fields[1].strip('@')
                # create a new Family and save it in mapping dictionary
                families[ref] = family(ref)
                # process remainder of the FAM record
                processFamily(families[ref])

            else:    # 0-level line, but not of interest -- skip it
                line = f.readline()
        else:    # skip lines until next candidate 0-level line
            line = f.readline()


# Test code starts here

def runDemo():
    # filename = "Kennedy.ged"  # Set a default name for the file to be processed
    # Uncomment the next line to make the program interactive
    filename = input("Type the name of the GEDCOM file:")

    processGEDCOM(filename)
    print("START")
    print("END")
    # Print out all information stored about individuals
    for ref in sorted(persons.keys()):
        print(ref+':', persons[ref])

    # Print out all information stored about families
    for ref in sorted(families.keys()):
        print(ref+':', families[ref])
    print()

# person = "I46"  # Default selection to work with Kennedy.ged file
# Uncomment the next line to make the program interactive
    person = input("Enter person ID for descendants chart:")

    persons[person].printDescendants()


def _main():
    # runDemo()
    processGEDCOM("Kennedy.ged")
    p = persons['I1']
    print(p.eventObj._gender)
    # print( p.parentFamID() )
    # p.printAncestors(' ')

    # GEDtest.runtests(persons,families)
    # p = persons["I12"]
    # print(p.isDescendant("I8"))


if __name__ == '__main__':
    _main()
