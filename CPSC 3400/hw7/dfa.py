# CPSC 3400 - DFA simulator
import sys

# Get file names
dfaFile = open(sys.argv[1])
strFile = open(sys.argv[2])

# Get input alphabet
alphaLine = dfaFile.readline()
alpha = alphaLine.split()

# Intialize variables
dfa = []            # List of dictionaries: one per state
accepting = []      # List of accepting states 
state = 0           # Current state being processed

# Read in dfa file
for line in dfaFile:
    entry = {}
    lineList = line.split()
    if (lineList[0] == '+'):
        accepting.append(state)
    lineList = lineList[1:]
    lineList = [int(x) for x in lineList]
    dfa.append(dict(zip(alpha, lineList)))
    state += 1    

# Check each string in the string file
for line in strFile:
    line = line.rstrip()

    state = 0
    for c in line:
        state = dfa[state][c]

    if state in accepting:
        result = "ACCEPTED"
    else:
        result = "REJECTED"

    print("String:", line, "Final state:", state, result)

dfaFile.close()
strFile.close()
