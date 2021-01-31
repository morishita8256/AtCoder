#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define sz(x) ((ll)(x).size())
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

struct Doubling {
  const int LOG;
  vector<vector<int> > table;

  Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t)) {
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

  Doubling d(N, 1e+10);

  rep(i, N) {
    d.set_next(i, B[i]);
  }
  d.build();
  rep(i, N) {
    cout << d.query(i, D) + 1 << endl;
  }
}