#include <iostream>
#include <string>

using namespace std;

void getNext(const string &s, int next[])
{
    int j;
    j = next[0] = -1;
    for (int i = 0; i < s.size(); i++)
    {
        while (j != -1 && s[i] != s[j])
            j = next[j];
        next[i + 1] = ++j;
    }
}

int match()

int main()
{
    int next[100] = {0};
    string temp;
    while (cin >> temp &&temp != "-1")
    {
        getNext(temp, next);
        for (int i = 0; i <= temp.size(); i++)
        {
            cout << next[i] << " ";
        }
        cout << endl;
    }
    return 0;
}