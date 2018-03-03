n = input()
print(len(set(i for i in map(int, input().split()) if i != 0)))
