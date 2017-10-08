#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, goal, t;
    vector<int> pos;
    bool vis = false;
    cin >> T >> goal;
    T--;
    while (T--)
    {
        cin >> t;
        pos.push_back(t);
    }
    t = 0;
    while (t < pos.size())
    {
        if (t + pos[t] == goal - 1)
        {
            vis = true;
            break;
        }
        t += pos[t];
    }
    if (vis)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}