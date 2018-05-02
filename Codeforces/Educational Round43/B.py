n, m, k = map(int, input().split())

if k < n:
    print(k + 1, 1)
else:
    k -= n
    r = n - k // (m - 1)
    if r & 1:
        print(r, m - k % (m - 1))
    else:
        print(r, k % (m - 1) + 2)
