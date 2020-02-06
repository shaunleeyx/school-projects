"""
GEDtest.py

Test module for the family tree assignment derived from descendants.py
"""
def runtests(persons,families):
    
    # Optionally print out all information stored about individuals
    doPrint = input("Print persons info?")
    if doPrint in 'yY':
        for ref in sorted(persons.keys()):
            print(ref+':', persons[ref])

    # Optionally print out all information stored about families
    print()
    doPrint = input("Print families info?")
    if doPrint in 'yY':
        for ref in sorted(families.keys()):
            print(ref+':', families[ref])

    print()
    doPrint = input("Print descendants?")
    if doPrint in 'yY':
        print()
        person = "I46"  # Default selection to work with Kennedy.ged file
        # Uncomment the next line to make the program interactive
        # person = input("Enter person ID for descendants chart:")
        # persons[person].printDescendants()
        persons[person].printDescendants()
        print()

    print()
    doPrint = input("Test isDescendant?")
    if doPrint in 'yY':
        print()
        print('**** Tests of isDescendant')
        print('Expected answers are "is" "is" "is not" "is not"')
        #
        # NOTE: These tests use a name() function in person that
        #       prints just the name, without event information.
        #
        if persons["I46"].isDescendant('I55'): notString = ' '
        else: notString = ' not '
        print(persons["I55"].name() + ' is' + notString +
              'a descendant of ' + persons["I46"].name())
        if persons["I47"].isDescendant('I54'): notString = ' '
        else: notString = ' not '
        print(persons["I54"].name() + ' is' + notString +
              'a descendant of ' + persons["I47"].name())
        if persons["I46"].isDescendant('I53'): notString = ' '
        else: notString = ' not '
        print(persons["I53"].name() + ' is' + notString +
              'a descendant of ' + persons["I46"].name())
        if persons["I61"].isDescendant('I54'): notString = ' '
        else: notString = ' not '
        print(persons["I54"].name() + ' is' + notString +
              'a descendant of ' + persons["I61"].name())
        
    print()
    doPrint = input("Test printAncestors?")
    if doPrint in 'yY':
        print('**** Call to printAncestors for I55 (John Fitzgerald KENNEDY Jr.)')
        print()
        persons["I55"].printAncestors('')
        print()
##        persons["I55"].printAncestorsV2('')
##        print()

    print()
    doPrint = input("Test printCousins?")
    if doPrint in 'yY':
        print()
        persons["I54"].printCousins()  # Caroline KENNEDY
        print()
        persons["I82"].printCousins()  # Edwin Moore KENNEDY Jr.
        print()
        persons["I1"].printCousins()  # Joseph Patrick Kennedy
        print()
        persons["I49"].printCousins(1)   # Janet LEE
        print()
        persons["I81"].printCousins(2)   # John Bouvier Kennedy SCHLOSSBERG
