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
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

string t;

bool check(int l, int r)
{
    if (abs(l - r) % 2 == 0)
        return false;
    queue<char> q;
    int i = (l + r) / 2;
    int j = i + 1;
    for (;;)
    {
        
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    int len = t.size();
    set<pii> s;

    int i, j;
    int ti, tj;

    FOR(i, 0, len)
    FOR(j, i + 1, len)
    if (check(i, j))
    {
        cout << i << " " << j << endl;
        s.insert(mp(i, j));
    }

    cout << s.size() << endl;

    return 0;
}