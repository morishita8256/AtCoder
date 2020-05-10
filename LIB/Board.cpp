#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}


template <typename T>
struct board {
  int H, W, V;
  vector<vector<T>> B;

  board(vector<vector<T>>& mat) {
    H = mat.size(), W = mat[0].size();
    V = H * W;
    B = vector<vector<T>>(H, vector<T>(W));
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        B[i][j] = mat[i][j];
      }
    }
  }

  bool in(int v) {
    return 0 <= v && v < V;
  }

  bool in(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
  }

  T at(signed v) {
    int i = v / W, j = v % W;
    return B[i][j];
  }

  T at(signed i, signed j) {
    return B[i][j];
  }

  vector<T>& operator[](signed i) {
    return B[i];
  }

  friend ostream& operator<<(ostream& s, const board& b) {
    s << b.B;
    return s;
  }
};

signed main() {
  vector<vector<int>> mat(5, vector<int>(5));
  rep(i, 5) {
    rep(j, 5) {
      mat[i][j] = rand() % 5;
    }
  }
  cout << mat << endl;
  cout << '\n';

  board B(mat);
  rep(i, B.V) {
    cout << B.at(i);
  }
}