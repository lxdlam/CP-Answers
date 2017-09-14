#include <iostream>
#include <vector>

using namespace std;

int pattern(int a, int b, int c)
{
    if (a == c && a != b)
        return b == 1 ? 0 : 1;
    else
        return b;
}

template <typename T>
void copy(vector<T> &src, vector<T> &dest)
{
    dest.resize(src.size());
    copy(src.begin(), src.end(), dest.begin());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, t;
    cin >> T;
    vector<int> v1, v2;
    int count = 0;
    while (T--)
    {
        cin >> t;
        v1.emplace_back(t);
    }
    copy(v1, v2);
    int n = v1.size();
    while (true)
    {
        for (int i = 1; i < n - 1; i++)
            v2[i] = pattern(v1[i - 1], v1[i], v1[i + 1]);
        count++;

        if (v1 == v2)
        {
            count--;
            break;
        }
        copy(v2, v1);
    }
    cout << count << "\n";
    for (auto i : v1)
        cout << i << " ";
    return 0;
}