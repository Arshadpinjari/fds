total_book = int(input("Enter the no. of books:"))
books = []

for i in range(total_book):
    cost = int(input("Enter the cost of books:"))
    books.append(cost)

def delDup(books):
    noDup = []
    for item in books:
        if item not in noDup:
            noDup.append(item)
    return noDup

def ascending(books):
    books.sort()
    return books

def costly(books):
    count = 0
    for item in books:
        if item > 500:
            count += 1 
    return count

def lesscost(books):
    newlist = []
    for item in books:
        if item < 500:
            newlist.append(item)
    return newlist

unique_books = delDup(books)
sorted_books = ascending(books)
count_costly_books = costly(books)
cheap_books = lesscost(books)

print(f"Books without Duplicate entries: {unique_books}")
print(f"Books in ascending order: {sorted_books}")
print(f"No of books that cost more than 500: {count_costly_books}")
print(f"Books costing less than 500: {cheap_books}")
