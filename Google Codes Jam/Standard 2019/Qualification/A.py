T = int(input())

change = ['0', '0', '1', '1', '2', '2', '3', '2', '3', '3']
change_rev = [str(i - int(change[i])) for i in range(10)]

for kase in range(T):
    num = input()
    print(
        'Case #%d: %s %s' % (kase + 1, ''.join(change[int(it)] for it in num),
                             ''.join(change_rev[int(it)] for it in num)))
