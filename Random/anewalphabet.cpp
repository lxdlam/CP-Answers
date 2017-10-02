// Source: https://open.kattis.com/problems/anewalphabet
// From 2016 ICPC North American Qualifier Contest

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string m[] = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch + ('a' - 'A');
    return ch;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string src, res;
    getline(cin, src);
    transform(src.begin(), src.end(), src.begin(), toLower);
    for (int i = 0; i < src.size(); i++)
    {
        if (src[i] >= 'a' && src[i] <= 'z')
            res += m[src[i] - 'a'];
        else
            res += src[i];
    }
    cout << res << endl;
    return 0;
}