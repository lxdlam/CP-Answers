n = int(input())

s = input()

if s == '0':
    print(s)
else:
    print('1' + '0' * s.count('0'))