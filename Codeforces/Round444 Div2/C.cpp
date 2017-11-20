#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SIZE = 24 + 5;

int cube[SIZE];
int tcube[SIZE];

bool check()
{
    bool r1, r2, r3, r4, r5, r6;
    r1 = r2 = r3 = r4 = r5 = r6 = false;
    if (cube[1] == cube[2] && cube[2] == cube[3] && cube[3] == cube[4])
        r1 = true;
    if (cube[5] == cube[6] && cube[6] == cube[7] && cube[7] == cube[8])
        r2 = true;
    if (cube[9] == cube[10] && cube[10] == cube[11] && cube[11] == cube[12])
        r3 = true;
    if (cube[13] == cube[14] && cube[14] == cube[15] && cube[15] == cube[16])
        r4 = true;
    if (cube[17] == cube[18] && cube[18] == cube[19] && cube[19] == cube[20])
        r5 = true;
    if (cube[21] == cube[22] && cube[22] == cube[23] && cube[23] == cube[24])
        r6 = true;
    return r1 && r2 && r3 && r4 && r5 && r6;
}

bool solve()
{
    int t1, t2;

    // face 1
    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[13];
    t2 = cube[14];
    cube[13] = cube[5];
    cube[14] = cube[6];
    cube[5] = cube[17];
    cube[6] = cube[18];
    cube[17] = cube[21];
    cube[18] = cube[22];
    cube[21] = t1;
    cube[22] = t2;
    t1 = cube[1];
    cube[1] = cube[3];
    cube[3] = cube[4];
    cube[4] = cube[2];
    cube[2] = t1;
    if (check())
        return true;

    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[13];
    t2 = cube[14];
    cube[13] = cube[21];
    cube[14] = cube[22];
    cube[21] = cube[17];
    cube[22] = cube[18];
    cube[17] = cube[5];
    cube[18] = cube[6];
    cube[5] = t1;
    cube[6] = t2;
    t1 = cube[1];
    cube[1] = cube[2];
    cube[2] = cube[4];
    cube[4] = cube[3];
    cube[3] = t1;
    if (check())
        return true;

    // face 2
    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[13 + 2];
    t2 = cube[14 + 2];
    cube[13 + 2] = cube[5 + 2];
    cube[14 + 2] = cube[6 + 2];
    cube[5 + 2] = cube[17 + 2];
    cube[6 + 2] = cube[18 + 2];
    cube[17 + 2] = cube[21 + 2];
    cube[18 + 2] = cube[22 + 2];
    cube[21 + 2] = t1;
    cube[22 + 2] = t2;
    t1 = cube[11];
    cube[11] = cube[9];
    cube[9] = cube[10];
    cube[10] = cube[12];
    cube[12] = t1;
    if (check())
        return true;

    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[13 + 2];
    t2 = cube[14 + 2];
    cube[13 + 2] = cube[5 + 2];
    cube[14 + 2] = cube[6 + 2];
    cube[5 + 2] = cube[17 + 2];
    cube[6 + 2] = cube[18 + 2];
    cube[17 + 2] = cube[21 + 2];
    cube[18 + 2] = cube[22 + 2];
    cube[21 + 2] = t1;
    cube[22 + 2] = t2;
    t1 = cube[11];
    cube[11] = cube[9];
    cube[9] = cube[10];
    cube[10] = cube[12];
    cube[12] = t1;
    if (check())
        return true;

    // face 3
    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[1];
    t2 = cube[3];
    cube[1] = cube[5];
    cube[3] = cube[7];
    cube[5] = cube[9];
    cube[7] = cube[11];
    cube[9] = cube[24];
    cube[11] = cube[22];
    cube[24] = t2;
    cube[22] = t1;
    t1 = cube[13];
    cube[13] = cube[14];
    cube[14] = cube[16];
    cube[16] = cube[15];
    cube[13] = t1;
    if (check())
        return true;

    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[1];
    t2 = cube[3];
    cube[1] = cube[24];
    cube[3] = cube[22];
    cube[24] = cube[9];
    cube[22] = cube[11];
    cube[9] = cube[5];
    cube[11] = cube[7];
    cube[5] = t1;
    cube[7] = t2;
    t1 = cube[13];
    cube[13] = cube[15];
    cube[15] = cube[16];
    cube[16] = cube[14];
    cube[14] = t1;
    if (check())
        return true;

    // face 4
    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[1 + 1];
    t2 = cube[3 + 1];
    cube[1 + 1] = cube[5 + 1];
    cube[3 + 1] = cube[7 + 1];
    cube[5 + 1] = cube[9 + 1];
    cube[7 + 1] = cube[11 + 1];
    cube[9 + 1] = cube[24 - 1];
    cube[11 + 1] = cube[22 - 1];
    cube[24 - 1] = t2;
    cube[22 - 1] = t1;
    t1 = cube[18];
    cube[18] = cube[17];
    cube[17] = cube[19];
    cube[19] = cube[20];
    cube[20] = t1;
    if (check())
        return true;

    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[1 + 1];
    t2 = cube[3 + 1];
    cube[1 + 1] = cube[24 - 1];
    cube[3 + 1] = cube[22 - 1];
    cube[24 - 1] = cube[9 + 1];
    cube[22 - 1] = cube[11 + 1];
    cube[9 + 1] = cube[5 + 1];
    cube[11 + 1] = cube[7 + 1];
    cube[5 + 1] = t1;
    cube[7 + 1] = t2;
    t1 = cube[18];
    cube[18] = cube[20];
    cube[20] = cube[19];
    cube[19] = cube[17];
    cube[17] = t1;
    if (check())
        return true;

    // face 5
    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[3];
    t2 = cube[4];
    cube[3] = cube[17];
    cube[4] = cube[19];
    cube[17] = cube[10];
    cube[19] = cube[9];
    cube[10] = cube[16];
    cube[9] = cube[14];
    cube[16] = t1;
    cube[14] = t2;
    t1 = cube[5];
    cube[5] = cube[6];
    cube[6] = cube[8];
    cube[8] = cube[7];
    cube[7] = t1;
    if (check())
        return true;

    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[3];
    t2 = cube[4];
    cube[3] = cube[16];
    cube[4] = cube[14];
    cube[16] = cube[10];
    cube[14] = cube[9];
    cube[10] = cube[17];
    cube[9] = cube[19];
    cube[17] = t1;
    cube[19] = t2;
    t1 = cube[5];
    cube[5] = cube[7];
    cube[7] = cube[8];
    cube[8] = cube[6];
    cube[6] = t1;
    if (check())
        return true;

    // face 6
    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[3 - 1];
    t2 = cube[4 - 1];
    cube[3 - 1] = cube[16 - 1];
    cube[4 - 1] = cube[14 - 1];
    cube[16 - 1] = cube[10 + 1];
    cube[14 - 1] = cube[9 + 1];
    cube[10 + 1] = cube[17 + 1];
    cube[9 + 1] = cube[19 + 1];
    cube[17 + 1] = t1;
    cube[19 + 1] = t2;
    t1 = cube[22];
    cube[22] = cube[24];
    cube[24] = cube[23];
    cube[23] = cube[21];
    cube[21] = cube[22];
    if (check())
        return true;

    memcpy(cube, tcube, sizeof(tcube));
    t1 = cube[3 - 1];
    t2 = cube[4 - 1];
    cube[3 - 1] = cube[16 - 1];
    cube[4 - 1] = cube[14 - 1];
    cube[16 - 1] = cube[10 + 1];
    cube[14 - 1] = cube[9 + 1];
    cube[10 + 1] = cube[17 + 1];
    cube[9 + 1] = cube[19 + 1];
    cube[17 + 1] = t1;
    cube[19 + 1] = t2;
    t1 = cube[22];
    cube[22] = cube[24];
    cube[24] = cube[23];
    cube[23] = cube[21];
    cube[21] = t1;
    if (check())
        return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 24; i++)
        cin >> tcube[i];

    if (solve())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}