T = int(input())


def get_ans(n, k, m):
    p = n // (k**m)
    return p - p // k


for _ in range(T):
    ln, rn, k, m = map(int, input().split())

    print(get_ans(rn, k, m) - get_ans(ln - 1, k, m))