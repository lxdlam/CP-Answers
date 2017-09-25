#include <string>
#include <iostream>
#include <vector>

using namespace std;

const string fl[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
const string sl[] = {"a", "b", "c", "d", "e", "f", "g", "h"};

void genName(vector<string> &v, int size)
{
    for (int i = 0; i < size; i++)
        v.push_back(fl[i / 8] + sl[i % 8]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> res;
    string temp;
    int T, size;
    cin >> T >> size;
    genName(res, T);
    for (int i = 0; i <= T - size; i++)
    {
        cin >> temp;
        if (temp == "NO")
            res[size + i - 1] = res[i];
    }
    for (auto i : res)
        cout << i << " ";
    return 0;
}