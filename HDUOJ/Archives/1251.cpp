#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node
{
    Node *next[26];
    int num;

    Node() : num(0)
    {
        for (int i = 0; i < 26; i++)
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
            if (node->next[s[i] - 'a'] == NULL)
                node->next[s[i] - 'a'] = new Node;
            node = node->next[s[i] - 'a'];
            node->num++;
        }
    }

    int query(const string &s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->next[s[i] - 'a'] == NULL)
                return 0;
            node = node->next[s[i] - 'a'];
        }
        return node->num;
    }

  private:
    void makeEmpty(Node *s)
    {
        if (s == NULL)
            return;
        for (int i = 0; i < 26; i++)
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
    string t;
    Trie trie;
    int n;
    while (getline(cin, t) && !t.empty())
        trie.insert(t);
    while (cin >> t)
        cout << trie.query(t) << endl;
    return 0;
}