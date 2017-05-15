#include <iostream>
#include <algorithm>

using namespace std;

class Team
{
  public:
    int number;
    int score;

    bool operator<(const Team &t)
    {
        return score > t.score;
    }
};

int main()
{
    int n, m;
    int win, lose;
    int count, temp;
    int max;
    cin >> n >> m;
    int *teams = new int[n];
    Team *res = new Team[n];
    for (int i = 0; i < n; i++)
    {
        teams[i] = i;
        res[i].number = i;
        res[i].score = 0;
    }
    while (m--)
    {
        cin >> win >> lose;
        teams[win - 1] = lose - 1;
    }
    for (int i = 0; i < n; i++)
    {
        count = 0;
        temp = i;
        while (teams[temp] != temp)
        {
            count++;
            temp = teams[temp];
        }
        res[i].score = count;
    }
    sort(res, res + n);
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == n)
            cout << res[i].number + 1 << endl;
        else
            cout << res[i].number + 1 << " ";
    }
    return 0;
}