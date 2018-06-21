n = input()
print(len(set(filter(lambda x: x != 0, map(int, input().split())))))
