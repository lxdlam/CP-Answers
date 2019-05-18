def solve():
    n = int(input())
    s = input()
    try:
        return 'YES' if n >= (s.index('8') + 11) else 'No'
    except:
        return 'NO'


print('\n'.join(solve() for _ in range(int(input()))))