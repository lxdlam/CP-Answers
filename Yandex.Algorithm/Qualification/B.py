n = int(input())

s = []
tt = []
k = []

for _ in range(2 * n):
    t = [i for i in map(int, input().split())]
    if len(set(s + t)) < len(s) + len(t):
        k = t
        continue
    s += t
    tt.append(t)

for i in range(n):
    if s[i] in k:
        pviot = i
        break

for i in sorted(tt, key=lambda x: k.index(x[pviot])):
    for j in i:
        print(j, end=' ')
