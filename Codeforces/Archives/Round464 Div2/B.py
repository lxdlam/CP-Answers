n, k = map(int, input().split())

s = [i for i in map(int, input().split())]

t = cur = res = 0

for i in range(k):
    if s[i] > n:
        continue
    con = (n // s[i]) * s[i]
    if cur < con:
        cur = con
        res = n // s[i]
        t = i + 1

if res == 0:
    t = 1
print(t, res)
