#include <bits/stdc++.h>

using namespace std;

class JumpingJackDiv1
{
    using ll = long long;

  private:
    // Constants

    // Useful Inner Method

    // Builder
    void build()
    {
    }

    // Solver
  public:
    int getLocationOfJack(int dist, int k, int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (i % k)
                ans += dist;

        return ans;
    }
};