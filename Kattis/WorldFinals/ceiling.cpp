#include <iostream>
#include <set>

using namespace std;

struct Node
{
    long long data = 0;
    Node *lch = nullptr;
    Node *rch = nullptr;
};

struct Tree
{
    Node *root = nullptr;

    void insert(long long data)
    {
        insert(data, root);
    }

    void insert(long long data, Node *&parent)
    {
        if (parent == nullptr)
        {
            parent = new Node;
            parent->data = data;
        }
        else if (data > parent->data)
        {
            insert(data, parent->rch);
        }
        else if (data < parent->data)
        {
            insert(data, parent->lch);
        }
    }

    bool operator==(const Tree &t) const
    {
        return compare(root, t.root);
    }

    bool operator!=(const Tree &t) const
    {
        return !(this->operator==(t));
    }

    bool compare(Node *l, Node *r) const
    {
        if (l == r && l == nullptr)
            return true;
        else if (l == nullptr || r == nullptr)
            return false;
        else
            return compare(l->lch, r->lch) && compare(l->rch, r->rch);
    }
};

struct cmp
{
    bool operator()(const Tree &ta, const Tree &tb)
    {
        return ta == tb;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long long t;
    set<Tree, cmp> s;
    cin >> n >> m;
    while (n--)
    {
        Tree tmp;
        for (int i = 0; i < m; i++)
        {
            cin >> t;
            tmp.insert(t);
        }
        s.insert(tmp);
    }

    cout << s.size() << endl;

    return 0;
}