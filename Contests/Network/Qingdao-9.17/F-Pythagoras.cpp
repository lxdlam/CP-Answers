#include <cstdio>
#include <vector>

using namespace std;

const int SIZE = 3e5 + 10;

long long ys[SIZE] = {0};
int bases[18] = {1};

void init()
{
    for (int i = 0; i < SIZE; i++)
        ys[i] = 2 * i * i + 2 * i;
    for (int i = 1; i < 18; i++)
        bases[i] = 2 * bases[i - 1];
}

int main()
{
    init();
    int T, k, t;
    long long res;
    scanf("%d", &T);
    vector<int> v;
    while (T--)
    {
        res = 0;
        v.clear();
        scanf("%d", &k);
        for (int i = 0; i < bases[k]; i++)
        {
            scanf("%d", &t);
            v.push_back(t);
        }
        for (int i = 0; ys[i] < 1e9; i++)
            res += v[ys[i] % bases[k]];
        printf("%lld", res);
    }
    return 0;
}