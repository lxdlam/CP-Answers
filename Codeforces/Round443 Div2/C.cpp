#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x = 0, y = 1023;
    int n, num;
    char token;
    cin >> n;
    while (n--)
    {
        cin >> token >> num;
        switch (token)
        {
        case '^':
            x ^= num;
            y ^= num;
            break;
        case '&':
            x &= num;
            y &= num;
            break;
        case '|':
            x |= num;
            y |= num;
            break;
        default:
            break;
        }
    }
    cout << 3 << endl;
    cout << "& " << (x | y) << endl;
    cout << "| " << (x & y) << endl;
    cout << "^ " << (x & (1023 ^ y)) << endl;
    return 0;
}