n = int(input())
s = input()

for i in range(len(s) - 1):
    if s[i:i + 2:] in ['UR', 'RU']:
        i += 2
        n -= 1

print(n)