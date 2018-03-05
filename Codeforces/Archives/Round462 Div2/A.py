n, m = map(int, input().split())

s1 = list(map(int, input().split()))
s2 = list(map(int, input().split()))

m = 0
tmp = -10**18 - 1

for i in s1:
    for j in s2:
        if i * j > tmp:
            m = i
            tmp = i * j

s1.remove(m)

tmp = -10**18 - 1

for i in s1:
    for j in s2:
        if i * j > tmp:
            m = i
            tmp = i * j

print(tmp)