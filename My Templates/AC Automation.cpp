#include <bits/stdc++.h>

using namespace std;

const int CHARSIZE = 26;
const char START = 'a';

const int SIZE = 5e5 + 10; // Change the size here to avoid MLE

// Array based AC-Automation
struct ACAuto
{
    int next[SIZE][CHARSIZE];
    int fail[SIZE], num[SIZE];
    int root;
    int size;

    ACAuto()
    {
        memset(next, 0, sizeof(next));
        memset(fail, 0, sizeof(fail));
        memset(num, 0, sizeof(num));
        init();
    }

    void init()
    {
        size = 0;
        root = newnode();
    }

    int newnode()
    {
        for (int i = 0; i < CHARSIZE; i++)
            next[size][i] = -1;
        num[size++] = 0;

        return size - 1;
    }

    void insert(const string &s)
    {
        int cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (next[cur][s[i] - START] == -1)
                next[cur][s[i] - START] = newnode();
            cur = next[cur][s[i] - START];
        }
        num[cur]++;
    }

    void build()
    {
        queue<int> q;
        int cur;
        fail[root] = root;
        for (int i = 0; i < CHARSIZE; i++)
        {
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            for (int i = 0; i < CHARSIZE; i++)
            {
                if (next[cur][i] == -1)
                    next[cur][i] = next[fail[cur]][i];
                else
                {
                    fail[next[cur][i]] = next[fail[cur]][i];
                    q.push(next[cur][i]);
                }
            }
        }
    }

    int query(const string &s)
    {
        int cur = root, res = 0, temp;
        for (int i = 0; i < s.size(); i++)
        {
            cur = next[cur][s[i] - 'a'];
            temp = cur;
            while (temp != root)
            {
                res += num[temp];
                num[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
};

// Below are linked implementation, may cause some problem
struct Node
{
    Node *next[CHARSIZE];
    Node *fail;
    int num;

    Node() : num(0), fail(NULL)
    {
        for (int i = 0; i < CHARSIZE; i++)
        {
            next[i] = NULL;
        }
    }
};

struct ACAuto
{
    Node *root;
    set<Node *> vis;

    ACAuto()
    {
        root = new Node;
    }

    void insert(const string &s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->next[s[i] - START] == NULL)
                node->next[s[i] - START] = new Node;
            node = node->next[s[i] - START];
        }
        node->num++;
    }

    int query(const string &s)
    {
        Node *cur = root;
        Node *temp;
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cur = cur->next[s[i] - START];
            temp = cur;
            while (temp != root)
            {
                res += temp->num;
                temp->num = 0; // Avoid matches too many times
                temp = temp->fail;
            }
        }
        return res;
    }

    void build()
    {
        queue<Node *> q;
        Node *cur;
        root->fail = root;
        for (int i = 0; i < CHARSIZE; i++)
        {
            if (root->next[i] == NULL)
                root->next[i] = root;
            else
            {
                root->next[i]->fail = root;
                q.push(root->next[i]);
            }
        }
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            for (int i = 0; i < CHARSIZE; i++)
            {
                if (cur->next[i] == NULL)
                    cur->next[i] = cur->fail->next[i];
                else
                {
                    cur->next[i]->fail = cur->fail->next[i];
                    q.push(cur->next[i]);
                }
            }
        }
    }
};