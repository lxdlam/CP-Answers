#include <iostream>
#include <algorithm>

using namespace std;

char list[] = {'8', '1', '1', '3', '6', '9', '4', '7', '0', '5'};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a;
    b = a;
    int lena = a.size();
    bool flag = true;
    transform(b.begin(), b.end(), b.begin(), [](char ch) {
        return list[ch - '0'];
    });
    for (int i = 0; i < lena; i++)
    {
        if (a[i] != b[lena - i - 1] || a[i] == '1' || a[i] == '2')
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}