T = int(input())

for kase in range(T):
    input()
    R = input()
    ans = []
    for it in R:
        if it == 'S':
            ans.append('E')
        else:
            ans.append('S')

    print("Case #", end='')
    print(kase + 1, end='')
    print(':', ''.join(ans))
