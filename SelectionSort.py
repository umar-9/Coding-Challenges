import random
def selection_sort(li):
    for start in range(len(li)):
        lowest = start
        for j in range(start + 1, len(li)):
            if li[j] < li[lowest]:
                lowest =  j
        li[start], li[lowest] = li[lowest], li[start]
    return li

print(selection_sort([random.randint(1,100) for i in range(100)]))