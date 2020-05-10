#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)


struct Doubling {
  const int LOG;
  vector<vector<int> > table;

  Doubling(int sz, int64_t lim_t = 1e+10) : LOG(64 - __builtin_clzll(lim_t)) {
    table.assign(LOG, vector<int>(sz, -1));
  }

  void set_next(int k, int x) {
    table[0][k] = x;
  }

  void build() {
    for (int k = 0; k + 1 < LOG; k++) {
      for (int i = 0; i < table[k].size(); i++) {
        if (table[k][i] == -1)
          table[k + 1][i] = -1;
        else
          table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int k, int64_t t) {
    for (int i = LOG - 1; i >= 0; i--) {
      if ((t >> i) & 1)
        k = table[i][k];
    }
    return k;
  }
};

/*
https://atcoder.jp/contests/abc013/tasks/abc013_4
*/

int main() {
  int N, M, D;
  cin >> N >> M >> D;
  vector<int> A(M);
  rep(i, M) {
    cin >> A[i];
    A[i]--;
  }

  vector<int> B(N);
  rep(i, N) {
    B[i] = i;
  }

  reverse(all(A));
  rep(i, M) {
    swap(B[A[i]], B[A[i] + 1]);
  }

  Doubling d(N);

  rep(i, N) {
    d.set_next(i, B[i]);
  }
  d.build();  // never forget!!

  rep(i, N) {
    cout << d.query(i, D) + 1 << endl;
  }
}