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
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

struct Doubling {
  const int LOG;
  vector<vector<int>> table;

  Doubling(int sz, int64_t lim_t = 1e+18 + 1)
      : LOG(64 - __builtin_clzll(lim_t)) {
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

signed main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
    A[i]--;
  }

  Doubling d(N);

  rep(i, N) {
    d.set_next(i, A[i]);
  }
  d.build();

  cout << (d.query(0, K) + 1) << endl;
}