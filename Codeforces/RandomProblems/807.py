n = int(input())
i = (n // 50) % 475
for _ in range(25):
    i = (i * 96 + 42) % 475
    print(26 + i, end=' ')
