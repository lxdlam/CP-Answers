# Source: https://open.kattis.com/problems/4thought
# From: 2013 ACM-ICPC North American Qualifier


def solve(n):
    ops = ['+', '-', '*', '/']
    for i in ops:
        for j in ops:
            for k in ops:
                s = "4 " + i + " 4 " + j + " 4 " + k + " 4"
                if round(eval(s)) == n:
                    print("%s = %d" % (s, n))
                    return
    print("no solution")
    return


def main():
    t = int(input())
    while t > 0:
        t -= 1
        n = int(input())
        solve(n)


main()