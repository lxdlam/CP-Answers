input()
ans = 0
s = input()
t = 0
for i in s:
    if i == 'x':
        t += 1
    elif t > 2:
        ans += t - 2
        t = 0
    else:
        t = 0
if t > 2:
    ans += t - 2
print(ans)