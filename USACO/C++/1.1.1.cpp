/*
ID: lxdlam1
PROG: test
LANG: C++11
*/

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream fin("test.in");
  ofstream fout("test.out");
  int a, b;
  fin >> a >> b;
  fout << a + b << endl;
  return 0;
}