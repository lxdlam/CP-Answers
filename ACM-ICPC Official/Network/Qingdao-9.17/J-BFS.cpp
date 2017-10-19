#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

#define MEM(x) memset(x, 0, sizeof(x));

int arr[100010] = {0};
int flag[100010] = {0};
set<int> s;

bool check(int size)
{
    set<int>::iterator it = s.begin();
    int l = *it;
    it++;
    for (it; it != s.end(); it++)
    {
        if (arr[l] < arr[*it])
            return false;
        l = *it;
    }
    return true;
}

void initset(int size)
{
    for (int i = 0; i < size; i++)
        s.insert(i);
}

int main()
{
    int T, k, count, l;
    scanf("%d", &T);
    while (T--)
    {
    
        MEM(arr);
        MEM(flag);
        count = 0;
        scanf("%d", &k);
        initset(k);
        for (int i = 0; i < k; i++)
            scanf("%d", &arr[i]);
        while (!check(k))
        {
            set<int>::iterator i = s.begin();
            int l = *i;
            i++;
            for(i;i!=s.end();i++){
                if()
            }
        }
        printf("%d\n", count);
        if (count != 0)
            for (set<int>::iterator it = s.begin(); it != s.end(); it++)
                printf("%d ", arr[*it]);
        else
            printf("\n");
    }
    return 0;
}