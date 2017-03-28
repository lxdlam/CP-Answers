/*
洛谷 P1421 小玉买文具
算法：无
入门题，不要输入float，直接都乘10然后一除就行
*/
#include <iostream>

const int price = 19;

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << (a * 10 + b) / 19 << endl;
    return 0;
}