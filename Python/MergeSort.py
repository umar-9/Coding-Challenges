def merge_sort(li):

    def split(arr):
        if len(arr) == 1:
            return arr
        return [split(arr[:len(arr)//2]), split(arr[len(arr)//2:])]


    def merge(arr):
        if len(arr) < 2:
            return arr

        left = merge(arr[0])
        right = merge(arr[1])
        new = []
        while len(left) > 0 and len(right) > 0:
            if left[0] < right[0]:
                new.append(left.pop(0))
            else:
                new.append(right.pop(0))
        new += left + right
        return new

    return merge(split(li))
