#include <iostream>
#include <vector>
#include <set>

using namespace std;

const string SPACES = "    ";

vector<string> split(string s, char token)
{
    vector<string> res;
    int i = 0;
    for (int pos = 0; pos < s.size(); pos++)
    {
        if (s[pos] == token)
        {
            res.push_back(s.substr(i, pos - i));
            i = pos + 1;
        }
    }
    res.push_back(s.substr(i, s.size() - i));
    return res;
}

struct Node
{
    string data;
    vector<Node> nodes;

    //done
    void print() const
    {
        cout << data << endl;
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << SPACES;
            nodes[i].print();
        }
    }
};

struct Tree
{
    Node root;

    void insert(string line)
    {
    }

    //done
    void print() const
    {
        root.print();
    }

    void insert(string parent, string child)
    {
    }

    bool operator<(Tree t)
    {
        return this->root.data < t.root.data;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string temp;
    int kase = 0;
    set<Tree> s;
    while (cin >> temp)
    {
        if (temp == "0")
        {
            cout << "Case " << (++kase) << ":" << endl;
            for (set<Tree>::iterator it = s.begin(); it != s.end(); it++)
                it->print();
            s.clear();
            continue;
        }
    }
    return 0;
}