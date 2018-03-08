from math import ceil

a, b = map(int, input().split())

while a != 0 and b != 0:
    if a >= 2 * b:
        k = ceil(a / (2 * b) - 1)
        if k == 0 and a - 2 * k * b > 0:
            k = 1
        a -= 2 * k * b
    elif b >= 2 * a:
        k = ceil(b / (2 * a) - 1)
        if k == 0 and b - 2 * a * k > 0:
            k = 1
        b -= 2 * k * a
    else:
        break

print(a, b)