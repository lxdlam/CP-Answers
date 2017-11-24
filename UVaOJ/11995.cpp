// FIXME:
// Runtime Error

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int op, num;
    bool iss, isq, ispq;
    while (cin >> n)
    {
        iss = isq = ispq = true;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        while (n--)
        {
            cin >> op >> num;
            if (op == 1)
            {
                s.push(num);
                q.push(num);
                pq.push(num);
            }
            else
            {
                if (s.empty() || num != s.top())
                    iss = false;
                if (q.empty() || num != q.front())
                    isq = false;
                if (pq.empty() || num != pq.top())
                    ispq = false;
                s.pop();
                q.pop();
                pq.pop();
            }
        }
        if (!iss && !isq && !ispq)
            cout << "impossible" << endl;
        else if ((iss && isq) || (iss && ispq) || (isq && ispq))
            cout << "not sure" << endl;
        else if (iss)
            cout << "stack" << endl;
        else if (isq)
            cout << "queue" << endl;
        else if (ispq)
            cout << "priority queue" << endl;
    }

    return 0;
}