n = int(input())
s = input()

val = ['??', 'C?C', 'M?M', 'Y?Y']

for i in ['CC', 'MM', 'YY']:
    if i in s:
        s = 'No'

if '?' not in s:
    s = 'No'

for i in val:
    if i in s or s == '?':
        s = 'Yes'
        break

if s[:2] in ['?C', '?Y', '?M']:
    s = 'Yes'

if s[-2:] in ['C?', 'Y?', 'M?']:
    s = 'Yes'

if s == 'Yes':
    print(s)
else:
    print('No')