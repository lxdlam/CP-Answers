import re

a, b = map(int, input().split())
s = input()

p = '[0-9]{' + str(a) + '}-[0-9]{' + str(b) + '}'

if re.match(p, s) is None:
    print('No')
else:
    print('Yes')
