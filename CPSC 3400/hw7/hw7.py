# Homework 7
import re

# REGULAR EXPRESSIONS

# Write patterns for regular expressions a-c here.
# You must use a single regular expression for each item.
# For part d, also include a substitution string.

a = re.compile(r"([$][0-9].[0-9][0-9])|[$][0-9]")

b = re.compile(r"[0-9]*3[0-9]*1[0-9]*4[0-9]*")

c = re.compile(r"^(\[((('[A-Za-z]')?)|(('[A-Za-z]', )*'[A-Za-z]'))\])")

#d = re.compile(r"(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec)\s*[0-9][0-9]?,?\s*[0-9]{4}")
d = re.compile(r"^(?P<Month>(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec))\s+"
               r"(?P<Day>([0-9][0-9]?)),?\s+"
               r"[0-9]?[0-9]?(?P<Year>([0-9][0-9]))$")
subStr = r"\g<Day> \g<Month> \g<Year>"   # Place what you want to substitute (used in sub)

# TESTS

# Write additional tests for each item.
# Include both matching and non-matching tests.
# A portion of your grade will be based on the thoroughness of your tests.

print("----Part a tests that match:")
print(a.search("$3.56"))

print("----Part a tests that do not match:")
print(a.search("3.56"))

print("----Part b tests that match:")
print(b.search("098388719400"))

print("----Part b tests that do not match:")
print(b.search("098388749100"))

print("----Part c tests that match:")
print(c.search("['H', 'e', 'l', 'l', 'o']"))

print("----Part c tests that do not match:")
print(c.search("['H', 'e', 'l', '7', 'o']"))

print("----Part d tests that match (and should change):")
print(d.sub(subStr, "May 29, 2019"))

print("----Part d tests that match (and should remain unchanged):")
print(d.sub(subStr, "May 29 19"))

