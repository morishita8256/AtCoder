#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
struct CumulativeSum2D {
  vector<vector<T>> data;

  CumulativeSum2D(int W, int H) : data(W + 1, vector<int>(H + 1, 0)) {
  }

  void add(int x, int y, T z) {
    ++x, ++y;
    if (x >= data.size() || y >= data[0].size())
      return;
    data[x][y] += z;
  }

  void build() {
    for (int i = 1; i < data.size(); i++) {
      for (int j = 1; j < data[i].size(); j++) {
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  T query(int sx, int sy, int gx, int gy) {
    return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
  }
};

/*
https://atcoder.jp/contests/abc005/tasks/abc005_4
*/

int main() {
  int N;
  cin >> N;
  vector<vector<int>> D(N, vector<int>(N));
  rep(i, N) {
    rep(j, N) {
      cin >> D[i][j];
    }
  }
  int Q;
  cin >> Q;
  vector<int> P(Q);
  rep(i, Q) {
    cin >> P[i];
  }

  CumulativeSum2D<int> S(N, N);
  rep(i, N) {
    rep(j, N) {
      S.add(i, j, D[i][j]);
    }
  }
  S.build();


  vector<int> num_to_d(N * N + 1);
  rep(i, N) {
    rep(j, N) {
      repp(ii, i + 1, N) {
        repp(jj, j + 1, N) {
          int num = (ii - i) * (jj - j);
          int d = S.query(i, j, ii, jj);
          chmax(num_to_d[num], d);
        }
      }
    }
  }

  repp(i, 1, N * N) {
    chmax(num_to_d[i], num_to_d[i - 1]);
  }

  rep(q, Q) {
    cout << num_to_d[P[q]] << endl;
  }
}