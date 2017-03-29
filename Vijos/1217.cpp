#include <iostream>
#include <string>

using namespace std;

int main()
{
    char ch;
    string contest = "";
    while (ch = cin.get() && ch != 'E')
        if (ch != '\n' && ch != ' ')
            contest += ch;
    while()
}