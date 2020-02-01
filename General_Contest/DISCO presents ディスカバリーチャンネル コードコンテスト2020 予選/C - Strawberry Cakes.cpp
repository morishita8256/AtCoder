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
#define debug(var) cout << "[" << #var << "]\n" << var << "\n\n"
typedef long long ll;
const int INF = 1001001001;
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
      cout << '\n';
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

signed main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<char>> s(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> s[i][j];
    }
  }

  int k = 0;
  vector<vector<int>> a(H, vector<int>(W, 0));
  rep(i, H) {
    bool ok = false;
    rep(j, W) {
      if (s[i][j] == '#') {
        k++;
        ok = true;
      }
      if (ok)
        a[i][j] = k;
    }
  }

  rep(i, H) {
    repr(j, W - 2, 0) {
      if (a[i][j] == 0)
        a[i][j] = a[i][j + 1];
    }
  }

  repp(i, 1, H - 1) {
    rep(j, W) {
      if (a[i][j] == 0)
        a[i][j] = a[i - 1][j];
    }
  }

  repr(i, H - 2, 0) {
    rep(j, W) {
      if (a[i][j] == 0)
        a[i][j] = a[i + 1][j];
    }
  }

  cout << a << "\n";
}