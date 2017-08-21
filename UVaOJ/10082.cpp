#include <cstdio>
#include <string>

using namespace std;

const string table = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
  int ch, pos;
  while ((ch = getchar()) != EOF)
  {
    if ((pos = table.find(ch)) != -1)
      putchar(table[pos - 1]);
    else
      putchar(ch);
  }
  return 0;
}