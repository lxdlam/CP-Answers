n = int(input())

s = input().split()

res = set()

for i in s:
    res.add(''.join(sorted(set(i))))

print(len(res))