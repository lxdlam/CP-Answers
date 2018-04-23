ans = 0

for i in range(1, int(input()) + 1):
    if '9' in str(i) and i % 9 != 0:
        ans += 1

print(ans)