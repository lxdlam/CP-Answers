n, k = map(int, input().split())

print((n // (k + 1)) * 2 + min(2, n % (k + 1)))
