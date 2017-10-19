#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> split(string s)
{
    vector<string> res;
    int i = 0;
    for (int pos = 0; pos < s.size(); pos++)
    {
        if (s[pos] == ',' || s[pos] == '.')
        {
            res.push_back(s.substr(i, pos - i));
            i = pos + 1;
        }
    }
    res.push_back(s.substr(i, s.size() - i));
    return res;
}

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

void discard(string &s, char token)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == token)
        {
            while (s[i + 1] == token)
                s.erase(i, 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string, int> m;
    string temp;
    int max;
    while (getline(cin, temp))
    {
        if (temp == "####")
        {
            map<string, int>::iterator it = m.begin();
            max = it->second;
            temp = it->first;
            for (; it != m.end(); it++)
            {
                if (it->second >= max)
                {
                    max = it->second;
                    if (temp > it->first)
                        temp = it->first;
                }
            }
            cout << temp << ":" << max << endl;
            temp.clear();
            m.clear();
            continue;
        }
        else
        {
            discard(temp, ',');
            discard(temp, '.');
            vector<string> lines = split(temp);
            for (int i = 0; i < lines.size(); i++)
            {
                discard(lines[i], ' ');
                vector<string> words = split(lines[i], ' ');
                if (words.size() <= 1)
                    continue;
                else
                {
                    for (int i = 0; i < words.size() - 1; i++)
                    {
                        temp = words[i] + " " + words[i + 1];
                        if (m.count(temp) == 0)
                            m[temp] = 1;
                        else
                            m[temp]++;
                    }
                }
            }
        }
    }
    return 0;
}