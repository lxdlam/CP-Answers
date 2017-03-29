#include <iostream>

int a[100000] = {0};
int vis[100000] = {0};

using namespace std;

int main()
{
    int n, i = 0;
    int count = 0;
    cin >> n;
    while (n--)
        cin >> a[i++];
    for (n = 0; n < i; n++)
        for (int j = n + 1; j < i; j++)
            vis[a[n] + a[j]] = 1;
    for (int j = 0; j < i; j++)
        if (vis[a[j]])
            count++;
    cout << count << endl;
    return 0;
}