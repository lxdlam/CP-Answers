ch = ['A', 'B', 'C', 'D']
clen = {}
ans = {}
for i in ch:
    clen[i] = len(input()[2:])
    ans[i] = False

for i in clen.items():
    if len(
            list(
                filter(lambda x: x is not i and i[1] < 2 * x[1],
                       clen.items()))) == 3:
        ans[i] = True

if list(ans.values()).count(True) == 1:
    for a in ans.items():
        if a[1]:
            print(a[0])
else:
    print('C')