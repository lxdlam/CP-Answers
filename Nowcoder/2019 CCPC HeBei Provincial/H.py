T = int(input())
 
for _ in range(T):
    n, k = map(int, input().split())
    print((n ** k - 1) % 9 + 1)