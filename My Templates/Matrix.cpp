#include <bits/stdc++.h>

using namespace std;

template <class T>
struct Matrix {
  int row;
  int col;
  vector<vector<T>> data;

  Matrix(int _row = 0, int _col = 0) { resize(_row, _col); }

  Matrix(vector<vector<T>> d) {
    row = d.size();
    col = d[0].size();
    data.resize(row);
    for (int i = 0; i < row; i++)
      for (int j = 0; j < col; j++) data[i].push_back(d[i][j]);
  }

  void resize(int _row, int _col) {
    row = _row;
    col = _col;
    data.resize(row);
    for (auto &i : data) i.resize(col);
  }

  T trace() {
    if (col != row) return -1;
    T ans = 0;
    for (int i = 0; i < row; i++) ans += data[i][i];
    return ans;
  }

  vector<T> &operator[](int pos) { return ref(data[pos]); }

  Matrix<T> operator-() {
    Matrix t(this->data);
    for (auto &i : t.data) {
      for (auto &j : i) {
        j = -j;
      }
    }
    return t;
  }

  bool empty() { return row == 0 || col == 0; }
};

template <class T>
Matrix<T> add(Matrix<T> a, Matrix<T> b, T mod = 1e9 + 7) {
  Matrix<T> temp;

  if (a.row != b.row || a.col != b.col) return temp;

  temp.resize(a.row, a.col);

  for (int i = 0; i < temp.row; i++) {
    for (int j = 0; j < temp.col; j++) temp[i][j] = (a[i][j] + b[i][j]) % mod;
  }
}

template <class T>
Matrix<T> minus(Matrix<T> a, Matrix<T> b, T mod = 1e9 + 7) {
  return add(a, -b);
}

template <class T>
Matrix<T> mul(Matrix<T> a, Matrix<T> b, T mod = 1e9 + 7) {
  Matrix<T> temp;

  if (a.col != b.row) return temp;

  temp.resize(a.row, b.col);

  for (int i = 0; i < a.row; i++) {
    for (int k = 0; k < a.col; k++) {
      auto t = a[i][k] % mod;
      for (int j = 0; j < b.col; j++)
        temp[i][j] = (temp[i][j] + t * b[k][j] % mod) % mod;
    }
  }

  return temp;
}

template <class T>
Matrix<T> fp(Matrix<T> base, T expr, T mod = 1e9 + 7) {
  Matrix<T> ans(base.data), t(base.data);
  expr--;
  while (expr) {
    if (expr & 1) ans = mul(ans, t, mod);
    t = mul(t, t, mod);
    expr >>= 1;
  }
  return ans;
}