#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SIZE = 86 + 10;

ll lucas[SIZE] = {2, 1};

void init()
{
    for (int i = 2; i < SIZE; i++)
        lucas[i] = lucas[i - 1] + lucas[i - 2];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    int n;
    cin >> n;
    cout << lucas[n] << endl;

    return 0;
}