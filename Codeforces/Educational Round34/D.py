def main():
    n = int(input())
    v = list(map(int, input().split()))
    m = dict()
    res = 0

    for i in v:
        if i not in m:
            m[i] = 0
        m[i] += 1
    k = v.copy()

    for i in range(n - 1, 0, -1):
        k[i - 1] = k[i] + k[i - 1]

    for i in range(0, n - 1):
        res += -(n - i - 1) * v[i] + k[i + 1]
        m[v[i]] -= 1
        if v[i] + 1 in m:
            res -= m[v[i] + 1]
        if v[i] - 1 in m:
            res += m[v[i] - 1]

    print(res)


if __name__ == '__main__':
    main()
