k, a, b = map(int, input().split())

print((abs((b - a) + 1)) // k + (1 if a <= 0 and b > 0 else 0))
