from collections import defaultdict

n, a, b = map(int, input().split())

res = defaultdict(lambda: 0)
t = defaultdict(lambda: 0)

ans = 0

for _ in range(n):
    k, x, y = map(int, input().split())
    ans += res[a * x - y] - t[(x, y)]
    res[a * x - y] += 1
    t[(x, y)] += 1

print(ans * 2)
