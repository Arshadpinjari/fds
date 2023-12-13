cricket = set()
badminton = set()
football = set()

total_cricket = int(input("Enter the total number of student who play cricket"))
for i in range (total_cricket):
    a=int (input("Enter the roll no. of student"))
    cricket.add(a)

total_badminton = int(input("Enter the total number of student who play badminton"))
for j in range (total_badminton):
    b=int (input("Enter the roll no. of student"))
    badminton.add(b)

total_football = int(input("Enter the total number of student who play football"))
for k in range (total_football):
    c=int (input("Enter the roll no. of student"))
    football.add(c)
    
students_cricket_but = (cricket.intersection (badminton))
students_cricket_or_badminton = (cricket.symmetric_difference (badminton))
students_neither_cricket_or_badminton = len(football.difference(cricket.difference(badminton)))
students_cricket_football = len(cricket.intersection(football))

print("students who play bith cricket and badminton", list(students_cricket_but))
print("students who play either cricket or badminton but not both", list(students_cricket_or_badminton))
print("students who play neither cricket not badminton", (students_neither_cricket_or_badminton))
print("students who play cricke and football but not badminton", (students_cricket_football))