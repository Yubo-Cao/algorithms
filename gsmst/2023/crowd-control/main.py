mllh_capacity, mllh_s = map(int, input().split())
lllh_capacity, lllh_students = map(int, input().split())
caf_capacity, caf_students = map(int, input().split())

# Move students from LLLH to CAF
move = min(lllh_students, caf_capacity - caf_students)
lllh_students -= move
caf_students += move

# Move students from MLLH to LLLH
move = min(mllh_s, lllh_capacity - lllh_students)
mllh_s -= move
lllh_students += move

# Move students from CAF to MLLH
move = min(caf_students, mllh_capacity - mllh_s)
mllh_s += move
caf_students -= move

print(mllh_s, lllh_students, caf_students, sep='\n')