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
    char s[5050];
    cin >> s;
    int n = strlen(s);
    int r = 0;
    FOR(i, 0, n)
    {
        int sp = 0, sp2 = 0;
        int b = 0;
        FOR(j, i, n)
        {
            if (s[j] == '(')
            {
                b++;
            }
            else if (s[j] == ')')
            {
                b--;
                if (b < 0 && sp > 0)
                {
                    b++;
                    sp--;
                }
                else if (b < 0 && sp2 > 0)
                {
                    b++;
                    sp2--;
                    sp++;
                }
                else if (b < 0)
                {
                    break;
                }
            }
            else
            {
                sp++;
                if (b > 0)
                {
                    sp--;
                    b--;
                    sp2++;
                }
            }
            if (b == 0 && sp % 2 == 0)
            {
                r++;
            }
        }
    }
    cout << r << endl;
    return 0;
}