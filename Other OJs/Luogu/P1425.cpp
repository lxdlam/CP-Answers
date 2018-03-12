/*
洛谷 P1425 小鱼的游泳时间
算法：无
很简单。
*/
#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (d > b ? c - a : c - a - 1) << " " << (d > b ? d - b : 60 + d - b) << endl;
}