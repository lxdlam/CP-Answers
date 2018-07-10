T = int(input())


def match(A, B):
    i = j = 1
    while True:
        if i > len(A):
            return True
        if j > len(B):
            return False
        if A[i - 1] == B[j - 1]:
            i += 1
            j += 1
        elif i == 1:
            j += 1
        else:
            i = 1


def solve(s):
    ans = s
    for j in range(1, len(s) + 1):
        ans = s[0:j] + s
        if not match(s, ans):
            return ans
    return 'Impossible'


for i in range(1, T + 1):
    s = input()
    print(f'Case #{i}:', solve(s))
