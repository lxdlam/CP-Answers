n = int(input())
s = input()

m = ''
for i in range(1, len(s)):
    if s[0:i] == s[i:i * 2] and len(s[0:i]) > len(m):
        m = s[0:i]

if len(m) == 0:
    print(len(s))
else:
    print(len(s) - len(m) + 1)
