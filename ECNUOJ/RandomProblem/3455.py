T = int(input())
fmt = "Case #{}: {}"

for _ in range(1, T + 1):
    a, n, p = map(int, input().split())
    a %= p
    for i in range(1, n + 1):
        a = (a**i) % p
    print(fmt.format(_, a))
