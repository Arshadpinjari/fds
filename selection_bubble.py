def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

score = [85.5, 92.0, 78.5, 89.5, 95.0, 87.5, 91.0, 83.0, 79.5, 88.0]

selection_sort(score)

print("sorted score using selecttion sort:" )
for scores in score:
  print(scores)

bubble_sort(score)

print("sorted score using bubble sort:")
for scores in score:
  print(scores)

top_score= score[-5:]
print("\nTop 5 score:")
for scores in top_score:
  print(scores)

