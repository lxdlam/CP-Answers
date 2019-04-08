from math import gcd

T = int(input())


def test(A, st, L):
    ret = [0] * L
    ret[0] = A[0] // st
    for idx in range(1, L):
        g = A[idx - 1] // ret[idx - 1]
        if gcd(A[idx - 1], g) == 1:
            return False, []
        ret[idx] = g

    return True, ret


for kase in range(T):
    N, L = map(int, input().split())
    A = list(map(int, input().split()))
    prime = set()
    ans = list()

    for i in range(L):
        for j in range(i + 1, L):
            g = gcd(A[i], A[j])
            if g != 1 and g != A[i]:
                prime.add(g)
                prime.add(A[i] // g)
                prime.add(A[j] // g)

    prime = list(sorted(prime))

    for it in prime:
        if A[0] % it == 0:
            ret, ans = test(A, it, L + 1)
            if ret:
                break

    print("Case #%d: %s" % (kase + 1, ''.join(
        chr(ord('A') + prime.index(it)) for it in ans)))
