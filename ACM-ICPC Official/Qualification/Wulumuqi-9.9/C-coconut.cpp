#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int t;
    int T;
    int n, b;
    int coco;
    bool flag;
    scanf("%d", &T);
    while (T--)
    {
        v.clear();
        coco = 0;
        flag = true;
        scanf("%d%d", &n, &b);
        while (n--)
        {
            scanf("%d", &t);
            v.emplace_back(t);
        }
        for (int i = 0; i < v.size(); i++)
        {
            coco += v[i];
            scanf("%d", &t);
            coco -= t * b;
            if (coco < 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}