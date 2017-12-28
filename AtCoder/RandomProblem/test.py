N = int(input())

for h in range(1, 3501):
    for n in range(1, 3501):
        for w in range(1, 3501):
            if (4 * h * n * w == N * n * w + N * h * w + N * h * n):
                print("{} {} {}".format(h, n, w))
                exit(0)