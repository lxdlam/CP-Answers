PHI = int(1e9) + 6
MOD = int(1e9) + 7

while True:
    n = int(input())
    if n == 0:
        break
    t = pow(2, (n - 1 + PHI) % PHI + PHI, MOD)
    print(t * (t + 1) % MOD)