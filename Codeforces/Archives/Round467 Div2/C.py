k, d, t = map(int, input().split())

if k / t >= 1:
    ans = t
else:
    if k % d != 0:
        m = (k // d + 1) * d
    else:
        m = k
    sp = k / t + (m - k) / (2 * t)
    tp = 1 / sp
    ans = m * int(tp)
    rp = (1 - int(tp) * sp) * t
    if k >= rp > 0:
        ans += rp
    elif rp > k:
        ans += k + (rp - k) * 2

print(ans)