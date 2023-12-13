def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort(left) + middle + quick_sort(right)

percentages = [85, 92, 78, 95, 88, 80, 98]

sorted_percentages = quick_sort(percentages)

top_scores = sorted_percentages[-5:]

for score in top_scores:
    print(score)
