#include <bits/stdc++.h>

using namespace std;

class IntervalIntersections {
private:
  // Constants

  // Useful Inner Method

  // Builder
  void build() {}

  // Solver
public:
  int minLength(int x1, int y1, int x2, int y2) {
    build();

    if (x2 >= y1)
      return x2 - y1;
    else if (x1 >= y2)
      return x1 - y2;
    else
      return 0;
  }
};