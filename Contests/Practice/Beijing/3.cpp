#include <cstdio>
#include <string>
#include <map>
#include <sstream>

using namespace std;

inline void clean()
{
    getchar();
    getchar();
    getchar(); //###
    getchar(); //\n
}

int main()
{
    stringstream ss;
    map<string, int> m;
    string temp;
    char ch;
    int max;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '#')
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
            printf("%s:%d\n", temp.c_str(), max);
            temp.clear();
            m.clear();
            ss.str("");
            clean();
            continue;
        }
        else if (ch != ' ' && ch != '\n' && ch != ',' && ch != '.')
        {
            ss << ch;
            continue;
        }

        if (temp.empty())
        {
            temp = ss.str();
            ss.str("");
        }
        else
        {
            temp = temp + " " + ss.str();
            if (m.count(temp) == 0)
                m[temp] = 1;
            else
                m[temp]++;
            if (ch == '\n' || ch == ',' || ch == '.')
                temp.clear();
            else
                temp = ss.str();
            ss.str("");
        }
    }
    return 0;
}