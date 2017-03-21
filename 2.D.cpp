#include <iostream>

using namespace std;

void swap(long &a, long &b);

int main()
{
    long n, s1, v1, s2, v2, ans;
    cin >> all;
    cin.get();
    while (all--)
    {
        count++;
        cin >> n >> s1 >> v1 >> s2 >> v2;
        cout << "Case #" << count << ": " << ans << endl;
    }
    return 0;
}

void swap(long &a, long &b)
{
    long temp = b;
    b = a;
    a = temp;
}