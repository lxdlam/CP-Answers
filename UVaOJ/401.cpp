#include <iostream>
#include <string>

using namespace std;

const string mirror_table = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const string res[] = {" -- is not a palidrome.\n\n", " -- a regular palidrome.\n\n", " -- a mirrored string.\n\n", " -- is a mirrored palidrome.\n\n"};

int main()
{
    string str;
    int p, m;
    while (cin >> str)
    {
        p = m = 0;
        for (int i = 0; i < (str.size() + 1) / 2; i++)
            cout << str << res[p * 2 + m];
    }
    return 0;
}