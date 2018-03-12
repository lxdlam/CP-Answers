#include <iostream>

using namespace std;

int cells[81];

bool isRow(int);
bool isCol(int);
bool isSection(int);

int main()
{
    int n, i;
    bool isVaild = true;
    cin >> n;
    while (n--)
    {
        for (auto &k : cells)
            k = 0;
        i = 0;
        isVaild = true;
        while (i < 81)
            cin >> cells[i++];
        isVaild = isRow(0);
        if (isVaild)
            isVaild = isCol(0);
        if (isVaild)
            isVaild = isSection(0);
        cout << (isVaild ? "Right" : "Wrong") << endl;
        cin.get();
    }
    return 0;
}

bool isRow(int col)
{
    int times[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 9; i++)
    {
        times[cells[i * 9 + col]]--;
        if (times[cells[i * 9 + col]] < 0)
            return false;
    }
    return col == 8 ? true : isRow(col + 1);
}

bool isCol(int row)
{
    int times[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 9; i++)
    {
        times[cells[row * 9 + i]]--;
        if (times[cells[row * 9 + i]] < 0)
            return false;
    }
    return row == 8 ? true : isCol(row + 1);
}

bool isSection(int sec)
{
    int times[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = sec / 3 * 3; i <= sec / 3 * 3 + 2; i++)
    {
        for (int j = sec % 3 * 3; j <= sec % 3 * 3 + 2; j++)
        {
            times[cells[i * 9 + j]]--;
            if (times[cells[i * 9 + j]] < 0)
                return false;
        }
    }
    return sec == 8 ? true : isSection(sec + 1);
}