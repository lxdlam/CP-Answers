from itertools import permutations

base = list(range(1, 10))


def toNum(lst):
    return lst[0] * 100 + lst[1] * 10 + lst[2]


for i in permutations(base):
    a = toNum(i[0:3])
    b = toNum(i[3:6])
    c = toNum(i[6:9])
    if a * 2 == b and a * 3 == c:
        print(a, b, c)
