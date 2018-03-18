def main():
    T = int(input())
    for i in range(1, T + 1):
        sn = input()
        n = int(sn)
        ans = 0
        pos = len(sn) + 1
        for p, v in enumerate(sn):
            if v in '13579':
                pos = p
                break
        if pos == len(sn) + 1:
            ans = 0
        elif len(sn) == 1:
            ans = 1 if n & 1 else 0
        else:
            num = int(sn[pos])
            minn = sn[:pos] + str(num - 1) + '8' * (len(sn) - pos - 1)
            if num == 9:
                fp = ''.join(reversed(sn[:pos]))
                tp = 0
                for v in fp:
                    if v == '8':
                        tp += 1
                    else:
                        break
                if tp == len(fp):
                    fp = '0' * tp + '2'
                else:
                    fp = '0' * tp + str(int(fp[tp]) + 2) + fp[tp:]
                maxx = ''.join(reversed(fp)) + '0' * (len(sn) - pos)
            else:
                maxx = sn[:pos] + str(num + 1) + '0' * (len(sn) - pos - 1)
            ans = min(
                abs(n - int(minn.lstrip('0'))), abs(n - int(maxx.lstrip('0'))))
        print(f'Case #{i}: {ans}')


if __name__ == '__main__':
    main()