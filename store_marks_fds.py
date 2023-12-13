total_students = int(input("Enter total no. of students: "))
std = [int(input("Enter the marks of student: ")) for _ in range(total_students)]

def average(std):
    return sum(std) / len(std)

def highest_lowest(std):
    print("Highest score of class is:", max(std))
    print("Lowest score of class is: ", min(std))

def absent(std):
    return std.count(0)

def max_freq(std):
    max_frq = max((std.count(item), item) for item in set(std))
    print(f"The Marks with highest frequency is {max_frq[1]} and the frequency is {max_frq[0]}")

print(f"Average marks of class is {average(std)}")
highest_lowest(std)
print(f"No. of students who were absent are {absent(std)}")
max_freq(std)