from itertools import groupby

n = input()
arr = map(int, input().split())
k = list(map(lambda x: len(list(x[1])), groupby(arr)))
if max(k) != min(k):
    print("NO")
else:
    print("YES")
