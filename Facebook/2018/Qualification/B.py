T = int(input())

for kase in range(1, T + 1):
    n = int(input())
    [input() for i in range(0, n + 1)]
    if n & 1:
        print(f'Case #{kase}: 1\n0.0')
    else:
        print(f'Case #{kase}: 0')