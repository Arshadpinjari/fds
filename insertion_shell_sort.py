def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

def display_top_scores(arr):
    top_scores = sorted(arr, reverse=True)[:5]
    print("Top 5 Scores:")
    for score in top_scores:
        print(score)

percentages = [85.2, 78.5, 92.0, 88.6, 76.3, 95.4, 89.1, 91.8, 84.7, 79.9]

print("Original Percentages:")
print(percentages)

insertion_sort(percentages)
print("\nSorted Percentages using Insertion Sort:")
print(percentages)

shell_sort(percentages)
print("\nSorted Percentages using Shell Sort:")
print(percentages)

display_top_scores(percentages)
