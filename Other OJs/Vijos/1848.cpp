#include <iostream>

using namespace std;

int countNum(int, int);

int main()
{
    int end, target;
    int count = 0;
    cin >> end >> target;
    for (int i = 1; i <= end; i++)
        count += countNum(i, target);
    cout << count << endl;
}

int countNum(int num, int target)
{
    int count = 0;
    while (num)
    {
        if (target == num % 10)
            count++;
        num /= 10;
    }
    return count;
}