def count(s):
    res = 0
    for i in s:
        if i in ['0', '4', '6', '9', 'A', 'D']:
            res += 1
        elif i in ['8', 'B']:
            res += 2
    return res


def main():
    s = hex(int(input())).replace('0x', '').upper()
    print(count(s))


main()
