#include <iostream>
#include <string>
#include <set>

using namespace std;

const int CHARSIZE = 5;
const char START = 'a';

struct Node
{
    Node *next[CHARSIZE];
    string word;
    int num;

    Node() : word(""), num(0)
    {
        for (int i = 0; i < CHARSIZE; i++)
        {
            next[i] = nullptr;
        }
    }
};

struct Trie
{
    Node *root;
    set<string> sc;

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
            if (node->next[s[i] - START] == nullptr)
                node->next[s[i] - START] = new Node;
            node = node->next[s[i] - START];
        }
        node->word = s;
        node->num++;
    }

    int query(const string &s)
    {
        sc.clear();
        return dfs(s, root);
    }

    void clear()
    {
        this->~Trie();
        root = new Node;
    }

  private:
    void makeEmpty(Node *s)
    {
        if (s == nullptr)
            return;
        for (int i = 0; i < CHARSIZE; i++)
        {
            if (s->next[i] != nullptr)
            {
                makeEmpty(s->next[i]);
                delete s->next[i];
            }
        }
    }

    int dfs(const string &s, Node *node)
    {
        if (node == nullptr)
            return 0;
        if (s == "")
        {
            if (sc.count(node->word) || node->word.empty())
                return 0;
            sc.insert(node->word);
            return node->num;
        }
        if (s[0] != '?')
            return dfs(s.substr(1, s.size() - 1), node->next[s[0] - START]);
        int res = 0;
        for (int i = 0; i < 5; i++)
            res += dfs(s.substr(1, s.size() - 1), node->next[i]);
        res += dfs(s.substr(1, s.size() - 1), node);
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    Trie trie;
    string t;
    cin >> n >> m;
    while (n--)
    {
        cin >> t;
        trie.insert(t);
    }
    while (m--)
    {
        cin >> t;
        cout << trie.query(t) << endl;
    }
    return 0;
}