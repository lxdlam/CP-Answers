#include <iostream>

using namespace std;

int res[] = {4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517, 526, 535, 562, 576, 588, 627, 634, 636, 645};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;
    cout << res[a - 1] << endl;

    return 0;
}