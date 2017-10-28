#include <bits/stdc++.h>

using namespace std;

using namespace std;

const int CHARSIZE = 26;
const char START = 'a';

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
                temp->num = 0;
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