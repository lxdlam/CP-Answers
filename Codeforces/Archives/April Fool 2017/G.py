def process(x):
    return '++++++++++++++++++++++++++++++++++++++++++++++++' + ''.join(
        ['+' for i in range(0, x)]) + '.>'


def main():
    res = str(eval(input()))
    for i in res:
        print(process(int(i)))


main()