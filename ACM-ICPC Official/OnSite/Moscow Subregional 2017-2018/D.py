SIZE = 70
tt = [1] * SIZE

for i in range(1, SIZE):
    tt[i] = tt[i - 1] * 2


def decode(x):
    if x % 2 == 1:
        return -(x + 1) // 2
    return x // 2


n = int(input())
ll = map(int, input().split())

ans = k = 0

for t in ll:
    if t < 128:
        ans += t * tt[k]
        print(decode(ans))
        ans = k = 0
    else:
        ans += (t - 128) * tt[k]
        k += 7
