#include <cstdio>
#include <cstring>

const int MAXN = 1e6 + 5;
int table[MAXN] = {0};

void init()
{
  for (int i = 1; i < MAXN; i++)
  {
    int x = i, y = i;
    while (x)
    {
      y += x % 10;
      x /= 10;
    }
    if (table[y] == 0 || i < table[y])
      table[y] = i;
  }
}

int main()
{
  init();
  int t, q;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &q);
    printf("%d\n", table[q]);
  }
  return 0;
}