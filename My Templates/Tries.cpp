#include <bits/stdc++.h>

using namespace std;

const int CHARSIZE = 26;
const char START = 'a';

// Standard Linked Trie
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
            node->num++;
        }
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