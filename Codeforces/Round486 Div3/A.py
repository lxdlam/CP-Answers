n, k = map(int, input().split())

m = list(map(int, input().split()))

ans = set(m)

if len(set(ans)) < k:
    print('NO')
else:
    print('YES')
    for i in ans:
        if k == 0:
            break
        k -= 1
        print(m.index(i) + 1, end=' ')
