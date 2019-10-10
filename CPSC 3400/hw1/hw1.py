import sys
#path to students.txt = C:\\Users\\shaun\\OneDrive\\Desktop\\Code\\Python Projects\\students.txt
#read the file with student data
#C:\\Users\\shaun\\OneDrive\\Desktop\\Code\\Python Projects
def processFile():
    with open(sys.argv[1], 'r') as r:
        fileobj = r.readlines()    
        new_list = []
        for item in fileobj:
            parse = item.rstrip().split(" ")
            new_list.append(parse)
    return new_list

#creates and returns a dictionary with {id: gpa}
#1. need to calculate gpa from the classes

def sumWeight(list_data):
    if len(list_data) != 0:
        return sum(list_data)
def createStudentDict(data):
    scale = {
        'A': 4.0,
        'A-': 3.7,
        'B+': 3.3,
        'B': 3.0,
        'B-': 2.7,
        'C+': 2.3,
        'C': 2.0,
        'C-': 1.7,
        'D+': 1.3,
        'D-': 0.7,
        'D': 1.0,
        'F': 0
    }
    results = {}        

    for student_data in data:
        student_id = student_data[0]
        totalweighted_gpa = []
        totalweight = 0.0
        for element in range(len(student_data)):
            if student_data[3] != '0':
                if student_data[element] in scale.keys():
                    totalweighted_gpa.append(scale[student_data[element]]*float(student_data[element-1]))
                    totalweight += float(student_data[element-1])
                    
            else:
                totalweighted_gpa.append(0.0)
        if totalweight == 0:
                    results[student_id] = 0.0
        else:
            results[student_id] = (sumWeight(totalweighted_gpa)/totalweight)

    return results

#print(processFile())
print(createStudentDict(processFile()))
# for item in fileobj:
#     print(item)


# createRoster
# Parameters: Data structure returned from processFile, department (such as 'CPSC'), course
# number (such as '1430').
# Returns: A list with (id, first name, last name, grade) tuples.
# Description: Creates and returns a list of students that have taken the course specified by the
# parameters. Each entry in the list is a tuple that consists of the following (in this order): student
# id number (integer), first name (string), last name (string), grade (string)
def createRoster(data, department, courseNum):
    results = []
    for student_data in data:
        for i in range(len(student_data)):
            if department == student_data[i] and courseNum == student_data[i+1]:
                student_tuple = (int(student_data[0]), student_data[1], student_data[2], student_data[i+3])
                results.append(student_tuple)
    return results
    
print(createRoster(processFile(),'CPSC', '1420'))
            
            
# createCourseSet
# Parameters: Data structure returned from processFile
# Returns: A list of strings.
# Description: Creates and returns a set of all courses mentioned at least once in the file. Each
# item in the set must be a string with the department and course number concatenated together
# separated by a single space such as 'CPSC 1430'.
def createCourseSet(data):
    spliced_data = []
    courses = []
    for student_data in data:
        spliced_data.append(student_data[4:])
    for classes in spliced_data:
        for x in range(0, len(classes),4):
            courses.append(classes[x] + ' ' + classes[x+1])      
    courses=set(courses)
    return courses
        
print(createCourseSet(processFile()))
            
# printStudents
# Parameters: Data structure returned from processFile, dictionary returned from
# createStudentDict
# Returns: nothing (produces output instead)
# Description: Prints the name of each student and their GPA ordered by their student ID number
# (in ascending order).
def printStudents(data, student_dict):
    ordered = []
    keys = student_dict.keys()
    for key in keys:
        for student_data in data:
            if key == student_data[0]:
                ordered.append((key + ' ' + student_data[1] + ' ' + student_data[2] + ' ' + str(student_dict[key])))
    ordered = sorted(ordered)
    for string in ordered:
        print(string)
        
printStudents(processFile(), createStudentDict(processFile()))