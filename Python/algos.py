import time
import random

from BubbleSort import bubble_sort
from SelectionSort import selection_sort
from MergeSort import merge_sort

test_arr = [random.randint(1,1_000_000) for i in range(50_000)]

sorts = [["Merge Sort", merge_sort], ["sorted()", sorted], ["Selection Sort", selection_sort], ["Bubble Sort", bubble_sort]]

for i in sorts:
    print(f"{i[0]} started", end = ". ")
    start = time.time()
    x = i[1](test_arr)
    end = time.time()
    print(f"Execution time of {i[0]}: {end - start}\n")