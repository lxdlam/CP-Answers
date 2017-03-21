#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const int &a, const int &b);

int main()
{
    vector<int> v;
    int temp, count;
    bool isExit = false;
    while (true)
    {
        v.clear();
        count = 0;
        while (true)
        {
            cin >> temp;
            if (temp == 0)
                break;
            else if (temp == -1)
            {
                isExit = true;
                break;
            }
            v.push_back(temp);
        }
        if (isExit)
            break;
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < v.size(); i++)
            for (int j = i; j < v.size(); j++)
                if (2 * v[j] == v[i])
                    count++;
        cout << count << endl;
    }
    return 0;
}

bool comp(const int &a, const int &b)
{
    return a > b;
}