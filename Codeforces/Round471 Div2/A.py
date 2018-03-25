hh, mm = map(int, input().split())
h, d, c, n = map(int, input().split())

if hh >= 20:
    print(c * 0.8 * ((h + n - 1) // n))
else:
    t = (20 - 1 - hh) * 60 + 60 - mm
    H = h + t * d
    print(min(c * ((h + n - 1) // n), c * 0.8 * ((H + n - 1) // n)))
