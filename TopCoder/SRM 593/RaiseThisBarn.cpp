#include <bits/stdc++.h>

using namespace std;

class RaiseThisBarn
{
  public:
    int calc(string str)
    {
        int count = 0, res = 0, k = 0;
        for (auto i : str)
            if (i == 'c')
                count++;
        if (count % 2)
            return 0;
        else if (count == 0)
            return str.size() - 1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'c')
                k++;
            if (k * 2 == count)
            {
                for (int j = i + 1; str[j] != 'c'; j++)
                    res++;
                break;
            }
        }
        return res + 1;
    }
};