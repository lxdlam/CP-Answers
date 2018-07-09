T = int(input())

for _ in range(1, T + 1):
    n, k, v = map(int, input().split())
    s = [input() for __ in range(n)]
    st = ((v - 1) * k) % n
    print(f'Case #{_}:', ' '.join(
        sorted((s + s)[st:st + k], key=lambda x: s.index(x))))
