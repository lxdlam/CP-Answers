# To determine if the number is an infinite fraction
# just determine if the original number is an infinite fraction

from math import e, gcd
from sys import argv


def get(n: int) -> int:
    p = int(n // e) if int(n // e) == int(n / e + 0.5) else int(n // e) + 1
    while p % 2 == 0:
        p //= 2
    while p % 5 == 0:
        p //= 5
    return -n if n % p == 0 else n


if __name__ == "__main__":
    try:
        n = int(argv[1])
    except Exception:
        n = 100

    print(sum(get(i) for i in range(5, n + 1)))
