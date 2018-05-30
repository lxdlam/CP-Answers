ans = {
    'purple': 'Power',
    'green': 'Time',
    'blue': 'Space',
    'orange': 'Soul',
    'red': 'Reality',
    'yellow': 'Mind'
}

n = int(input())

for _ in range(n):
    s = input()
    ans.pop(s)

print(len(ans))

for k, v in ans.items():
    print(v)