#include <iostream>
#include <string>

using namespace std;

const string mirror_table = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const string res[] = {" -- is not a palindrome.\n\n", " -- is a regular palindrome.\n\n", " -- is a mirrored string.\n\n", " -- is a mirrored palindrome.\n\n"};

char toM(const char &ch)
{
    if ('A' <= ch && ch <= 'Z')
        return mirror_table[ch - 'A'];
    else
        return mirror_table[ch - '0' + 25];
}

int main()
{
    string str;
    int p, m;
    while (cin >> str)
    {
        p = m = 1;
        int len = str.size();
        for (int i = 0; i < (len + 1) / 2; i++)
        {
            if (str[i] != str[len - i - 1])
                p = 0;
            if (toM(str[i]) != str[len - i - 1])
                m = 0;
        }
        cout << str << res[m * 2 + p];
    }
    return 0;
}