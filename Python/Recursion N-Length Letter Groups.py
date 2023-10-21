def collect(s, n):
    if len(s[0:]) < n:
        return []
    arr = [s[0:n]] + collect(s[n:], n)
    return sorted(arr)