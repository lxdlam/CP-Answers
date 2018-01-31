#include <bits/stdc++.h>

#define FOR(_i, _s, _e) for (int _i = _s; _i < _e; _i++)
#if __cpluscplus > 201103L
#define FORE(_c) for (auto i : _c)
#define FORER(_c) for (auto &i : _c)
#else
#define FORE(_c)
#define FORER(_c)
#define nullptr NULL
#endif
#if __cplusplus > 201402L
#define VIS(_kind, _name, _size) \
    vector<_kind> _name(_size);  \
    for (auto &i : v)            \
        cin >> i;
#elif __cpluscplus > 201103L
#define VIS(_kind, _name, _size) \
    vector<_kind> _name;         \
    _name.resize(_size);         \
    for (auto &i : v)            \
        cin >> i;
#else
#define VIS(_kind, _name, _size)    \
    vector<_kind> _name;            \
    _name.resize(_size);            \
    for (int i = 0; i < _size; i++) \
        cin >> v[i];
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    char q[5050];
    int sol;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> q + 1;
    int n = strlen(q + 1);
    for (int i = 1; i < n; ++i)
    {
        int l = 0, r = 0;
        for (int j = i; j <= n; ++j)
        {
            if (q[j] == '(')
                ++l, ++r;
            if (q[j] == ')')
                --l, --r;
            if (q[j] == '?')
                --l, ++r;
            if (l < 0)
                l += 2;
            if (r < 0)
                break;
            if (l == 0)
                ++sol;
        }
    }
    cout << sol;
    return 0;
}