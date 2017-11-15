#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int a, b, c;
const int SIZE = 100 + 10;

bool vis[SIZE][SIZE] = {false};

string output[] = {
    "FILL(1)",
    "FILL(2)",
    "DROP(1)",
    "DROP(2)",
    "POUR(1,2)",
    "POUR(2,1)"};

struct Node
{
    int left;
    int right;
    vector<int> step;

    Node() : left(0), right(0) {}
};

vector<int> bfs()
{
    Node s;
    vis[0][0] = true;
    Node n, t;
    queue<Node> q;
    q.push(s);

    while (q.size())
    {
        t = q.front();
        q.pop();
        if (t.left == c || t.right == c)
            return t.step;

        // Fill 1
        n = t;
        n.left = a;
        if (!vis[n.left][n.right])
        {
            vis[n.left][n.right] = true;
            n.step.push_back(0);
            q.push(n);
        }

        // Fill 2
        n = t;
        n.right = b;
        if (!vis[n.left][n.right])
        {
            vis[n.left][n.right] = true;
            n.step.push_back(1);
            q.push(n);
        }

        // Drop 1
        n = t;
        n.left = 0;
        if (!vis[n.left][n.right])
        {
            vis[n.left][n.right] = true;
            n.step.push_back(2);
            q.push(n);
        }

        // Drop 2
        n = t;
        n.right = 0;
        if (!vis[n.left][n.right])
        {
            vis[n.left][n.right] = true;
            n.step.push_back(3);
            q.push(n);
        }

        // Pour 1 to 2
        n = t;
        if (n.left + n.right > b)
        {
            n.left = n.left + n.right - b;
            n.right = b;
        }
        else
        {
            n.right += n.left;
            n.left = 0;
        }
        if (!vis[n.left][n.right])
        {
            vis[n.left][n.right] = true;
            n.step.push_back(4);
            q.push(n);
        }

        // Pour 2 to 1
        n = t;
        if (n.left + n.right > a)
        {
            n.right = n.right + n.left - a;
            n.left = a;
        }
        else
        {
            n.left += n.right;
            n.right = 0;
        }
        if (!vis[n.left][n.right])
        {
            vis[n.left][n.right] = true;
            n.step.push_back(5);
            q.push(n);
        }
    }

    vector<int> empty;
    return empty;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    vector<int> res = bfs();
    if (res.size() == 0)
        cout << "impossible" << endl;
    else
    {
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++)
            cout << output[res[i]] << endl;
    }

    return 0;
}