#include <iostream>
#include <string>

using namespace std;

long long toBase(long long, int, int);
bool isPali(string);
long long reverse(long long);

int main()
{
    int n, step = 0;
    long long m;
    cin >> n >> m;
    while (step != 30 && !isPail(to_string(m)))
    {
        m = toBase(toBase(m, n, 10) + toBase(reverse(m), n, 10), 10, n);
        step++;
    }
    if (step == 30)
        cout << "Impossible!" << endl;
    else
        cout << "STEP=" << step << endl;
    return 0;
}

long long toBase(long long num, int preBase, int tarBase)
{
    return 0;
}

bool isPail(string src)
{
    string dest = "";
    for (int i = src.size() - 1; i >= 0; i--)
        dest += src[i];
    return src == dest;
}

long long reverse(long long num)
{
    long long res = 0;
    while (num)
    {
        res *= 10;
        res += num % 10;
        num /= 10;
    }
    return res;
}