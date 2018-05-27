s = input()
ans = s

for i in range(1, len(s) - 1):
    for j in range(i + 1, len(s)):
        ans = min(ans, ''.join(reversed(s[:i])) + ''.join(reversed(s[i:j])) +
                  ''.join(reversed(s[j:])))

print(ans)