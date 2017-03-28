/*
ID: lxdlam1
PROG: gift1
LANG: C++11
*/

class Person
{
    string name;
    int money;

    Person(string name)
    {
        this.name = name;
        money = 0;
    }

    void setMoney(int money)
    {
        this.money += money;
    }
}

#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    vector<Person> v;
    string pa;
    int a;
    fin >> a;
    while (a--)
    {
        fin >> pa;
        Person temp(pa);
        v.push_back(temp);
    }

    

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
        fout << it->name << " " << it->money << endl;

    v.clear();
    fin.close();
    fout.close();
    return 0;
}

int findPerson(const vector<Person> &v, Person p)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i].name == p.name)
            return i;
    return -1;
}