# Turing machine simulator
# by Eric Larson (elarson@seattleu.edu)

# Original Author: Matt Chu (mwc2110@columbia.edu)

import sys
from optparse import OptionParser

COMMENT = "#"
BLANK = "B"
LEFT = "L"
RIGHT = "R"

# Parses command line
def parse_command_line():
    parser = OptionParser()

    parser.add_option("-d", "--display_mode", dest = "display_mode",
    help = "Display mode")
    parser.add_option("-t", "--tm_file", dest = "machine_file",
    help = "Turing machine file (.tur)")
    parser.add_option("-s", "--string", dest = "tape_string",
    help = "Initial string")

    options, args = parser.parse_args()

    if options.machine_file == None:
        options.machine_file = input("Enter the name of the machine file: ")
    if options.tape_string == None:
        options.tape_string = input("Enter the starting string: ")
    if options.display_mode == None:
        valid = False
        while not valid:
            print("Select display mode:")
            print("1. Step through the program (stops after each step)")
            print("2. Display each step (does not stop until the machine halts)")
            print("3. Display the final state (does not stop until the machine halts)")
            choice = int(input("Your choice: "))
            if choice == 1:
                options.display_mode = "step"
                valid = True
            elif choice == 2:
                options.display_mode = "show"
                valid = True
            elif choice == 3:
                options.display_mode = "final"
                valid = True
            else:
                print("Invalid choice")
    if not options.display_mode in ("step", "show", "final"):
        print("Invalid display mode")
        sys.exit(-1)

    return options.machine_file, options.tape_string, options.display_mode

# Loads machine from file
def load_machine(machine_file):
    machine = {}

    # Traverse the file
    file = open(machine_file, 'r')
    lines = file.readlines()
    instruction = lines[0].strip().replace(' ','').split(',')
    start_state = instruction[0]
    accept_state = instruction[1]
    for line in lines[1:]:

        # Ignore blank lines and comments
        if line.strip() == "" or line.strip()[0] == COMMENT:
            continue

        # Split the line into its pieces
        instruction = line.strip().replace(' ','').split(',')
        current_state = instruction[0]
        current_symbol = instruction[1]
        next_state = instruction[2]
        write_symbol = instruction[3]
        direction = instruction[4].upper()
        
        # Add the (key, value) to the dictionary
        key = (current_state, current_symbol)
        value = (write_symbol, next_state, direction)

        if current_state == accept_state:
            print("ERROR! Transitions are not allowed out of accept state")
            sys.exit(-1)
            
        if not key in machine:
            machine[key] = value
        else:
            print("ERROR! Duplicate key detected:", key)
            sys.exit(-1)

    return machine, start_state, accept_state


# Converts the tape into a list
def load_tape(tape_string):
    tape = []
    for i in range(len(tape_string)):
        tape.append(tape_string[i])
    if (len(tape) == 0):
      	tape.append("B")
    return tape

# Print the state of the machine
def print_state(tape, machine_position, machine_state, step):
    line1 = ""  # Stores the tape
    line2 = ""  # Stores the head pointer
    line3 = ""  # Stores the current state

    for i in range(len(tape)):
        line1 += tape[i]
        if i == machine_position:
            line2 += "^"
            line3 += machine_state
        else:
            line2 += " "
            line3 += " "
    print(line1 + "\n" + line2 + "\n" + line3)
    
    if step:
        input("")
    else:
        print ("")

# Execute the machine 
def execute(machine, start_state, tape, display_mode):

    # Initialize the machine
    current_state = start_state
    current_position = 0
    current_symbol = tape[current_position]

    # Print state
    if display_mode == "step":
        print_state(tape, current_position, current_state, True)
    elif display_mode == "show":
        print_state(tape, current_position, current_state, False)
    
    # Continue until machine halts (key does not exist)
    while (current_state, current_symbol) in machine:
        
        # Look up next move
        write_symbol, next_state, direction = machine[(current_state, current_symbol)]

        # Write new symbol
        tape[current_position] = write_symbol

        # Change state
        current_state = next_state

        # Move
        if direction == LEFT:
            current_position -= 1
        elif direction == RIGHT:
            current_position += 1
        else:
            print("ERROR! Invalid direction:", direction)
            sys.exit(-1)
        
        # Check to see if we are at the end of the tape
        if current_position == -1:
            tape.insert(0, BLANK)
            current_position = 0
        elif current_position == len(tape):
            tape.append(BLANK)

        # Update current symbol
        current_symbol = tape[current_position]

        # Print state
        if display_mode == "step":
            print_state(tape, current_position, current_state, True)
        elif display_mode == "show":
            print_state(tape, current_position, current_state, False)

    return current_state, tape

# Converts the tape back to a string
def tape_to_string(tape):
    
    # Convert to string
    tape_str = ""
    for c in tape:
       tape_str += c

    # Strip off leading and trailing blanks
    tape_str = tape_str.lstrip(BLANK)
    tape_str = tape_str.rstrip(BLANK)

    # If string only contained blanks, return a single blank
    if len(tape_str) == 0:
        return BLANK
 
    return tape_str 

if __name__ == "__main__":
    # Parse command line.
    machine_file, tape_string, display_mode = parse_command_line()

    # Load the program.
    machine, start_state, accept_state = load_machine(machine_file)

    # Load the initial tape.
    tape = load_tape(tape_string)

    # Execute the machine on the tape.
    final_state, final_tape = execute(machine, start_state, tape, display_mode)

    # Print the final tape.
    if final_state == accept_state:
        acceptStr = "(accepting)"
    else:
        acceptStr = "(rejecting)"
    print("State:", final_state, acceptStr, "Tape:", tape_to_string(final_tape))
