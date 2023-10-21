def bubble_sort(li):
    swap = True
    while swap == True:
        swap = False
        for idx in range(len(li)-1):
            if li[idx] > li[idx + 1]:
                li[idx], li[idx + 1] = li[idx + 1], li[idx]
                swap = True
    return li
