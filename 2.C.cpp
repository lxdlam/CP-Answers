#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int number;
    int same;
    int allsame;
};

int sameNumber(int num1, int num2);
int samePlace(int num1, int num2);
int min(const int &a, const int &b);

int main()
{
    int count, n, s, as, ans;
    bool isFind;
    vector<Node *> v;
    Node *temp;
    while (true)
    {
        for (int i = 0; i < v.size(); i++)
            delete v[i];
        v.clear();
        ans = 0;
        cin >> count;
        if (!count)
            break;
        while (count--)
        {
            cin >> n >> s >> as;
            temp = new Node;
            temp->number = n;
            temp->same = s;
            temp->allsame = as;
            v.push_back(temp);
        }
        for (int i = 1000; i <= 9999; i++)
        {
            isFind = true;
            for (int j = 0; j < v.size(); j++)
                if (sameNumber(v[j]->number, i) != v[j]->same || samePlace(v[j]->number, i) != v[j]->allsame)
                    isFind = false;
            if (isFind)
                ans = ans == 0 ? i : 1;
        }
        if (ans == 1)
            cout << "Not sure" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}

int sameNumber(int num1, int num2)
{
    int count = 0;
    int digit1[10] = {0}, digit2[10] = {0};
    while (num1 && num2)
    {
        digit1[num1 % 10]++;
        digit2[num2 % 10]++;
        num1 /= 10;
        num2 /= 10;
    }
    for (int i = 0; i <= 9; i++)
        if (digit1[i] && digit2[i])
            count += min(digit1[i], digit2[i]);
    return count;
}

int samePlace(int num1, int num2)
{
    int count = 0;
    while (num1 && num2)
    {
        if (num1 % 10 == num2 % 10)
            count++;
        num1 /= 10;
        num2 /= 10;
    }
    return count;
}

int min(const int &a, const int &b)
{
    return a > b ? b : a;
}