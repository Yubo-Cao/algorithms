import re
s = input()
print(re.match("e(19|20)\d{7}|\d{9}", s) and "VALID" or "INVALID")