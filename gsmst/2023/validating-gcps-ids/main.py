import re

print("VALID" if re.match(r"e(19|20)\d{7}|\d{9}", input()) else "INVALID")
