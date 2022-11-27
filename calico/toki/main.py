"""
In toki pona phonotactics, words are made of one or more valid syllables. All
 valid syllables follow a (C)V(n) structure: an optional consonant, followed
 by a mandatory vowel, followed by an optional n. Consonants and vowels are
 single letters from the toki pona alphabet. The toki pona alphabet only has
 14 letters and is a subset of the English alphabet. These are:
 - The consonants m, n, p, t, k, s, w, j, l (n is a consonant, as well as an
   optional ending)
  - The vowels a, e, i, o, u
  - Finally, words must not contain any of these contiguous illegal sequences
    (including between syllables): wu, wo, ji, ti, nn, or nm
  - Adjacent vowels such as aa, ei, uo, aoi, etc.
"""

import re


def is_valid(s):
    if re.search(r"wu|wo|ji|ti|nn|nm", s):
        return False
    if re.search(r"[aeiou]{2,}", s):
        return False
    return re.match(r"^(?:[mnptkswjl]?[aeiou]n?)+$", s)


def main():
    for _ in range(int(input())):
        s = input()
        print("pona" if is_valid(s) else "ike")


if __name__ == "__main__":
    main()
