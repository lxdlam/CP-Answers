#include <bits/stdc++.h>

using namespace std;

class DancingClass
{
    const static int SIZE = 500 + 10;
    const double EPS = 1e-9;
    double c[SIZE][SIZE];

    void getCom()
    {
        c[0][0] = 1;
        for (int i = 1; i < SIZE; i++)
        {
            c[i][0] = 1;
            for (int j = 1; j <= i; j++)
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            // Will be extremely large!
        }
    }

  private:
    // Constants

    // Useful Inner Method

    // Builder
    void build()
    {
        getCom();
    }

    // Solver
  public:
    string checkOdds(int n, int k)
    {
        build();

        double ans = 0.0;

        for (int i = 0; i <= n; i++)
        {
            if (i * (n - i) >= k)
                ans += c[n][i] * pow(0.5, n);
        }

        if (abs(ans - 0.5) < EPS)
            return "Equal";
        else if (ans > 0.5)
            return "High";
        else
            return "Low";
    }
};