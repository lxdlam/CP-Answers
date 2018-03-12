#include <bits/stdc++.h>

using namespace std;

const int CHARSIZE = 26;
const char START = 'a';

struct Node
{
    Node *next[CHARSIZE];
    int num;

    Node() : num(0)
    {
        for (int i = 0; i < CHARSIZE; i++)
        {
            next[i] = NULL;
        }
    }
};

struct Trie
{
    Node *root;

    ~Trie()
    {
        makeEmpty(root);
        delete root;
    }

    Trie()
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
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->next[s[i] - START] == NULL)
                return 0;
            node = node->next[s[i] - START];
        }
        return node->num;
    }

    void clear()
    {
        this->~Trie();
        root = new Node;
    }

  private:
    void makeEmpty(Node *s)
    {
        if (s == NULL)
            return;
        for (int i = 0; i < CHARSIZE; i++)
        {
            if (s->next[i] != NULL)
            {
                makeEmpty(s->next[i]);
                delete s->next[i];
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, r;
    string t;
    set<string> s;
    Trie trie;
    while (cin >> t)
    {
        trie.insert(t);
        s.insert(t);
    }
    for (set<string>::iterator it = s.begin(); it != s.end(); it++)
    {
        t = *it;
        if (t.size() == 1)
            continue;
        for (int i = 1; i < t.size(); i++)
        {
            l = trie.query(t.substr(0, i));
            r = trie.query(t.substr(i, t.size()));
            if (l == r && l == 1)
            {
                cout << t << endl;
                break;
            }
        }
    }
    return 0;
}