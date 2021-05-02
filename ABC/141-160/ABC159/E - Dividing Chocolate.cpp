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

signed main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<int>> S(H, vector<int>(W));
  rep(i, H) {
    rep(j, W) {
      char c;
      cin >> c;
      S[i][j] = c - '0';
    }
  }

  int ans = INF;
  /* 2bit */
  rep(b, bit(H - 1)) {
    int temp = __builtin_popcount(b);
    int G = temp + 1;

    vector<int> cut(H - 1);
    rep(i, H - 1) {
      if ((b >> i) & 1)
        cut[i] = 1;
      else
        cut[i] = 0;
    }

    vector<int> r2g(H);  // row to group
    rep(i, H - 1) {
      r2g[i + 1] = r2g[i] + cut[i];
    }

    vector<int> group(G);
    rep(i, H) {
      group[r2g[i]] += S[i][0];
    }

    bool ok = true;
    rep(g, G) {
      if (group[g] > K)
        ok = false;
    }
    if (!ok)
      continue;

    repp(j, 1, W - 1) {
      rep(i, H) {
        group[r2g[i]] += S[i][j];
      }

      bool ok = true;
      rep(g, G) {
        if (group[g] > K)
          ok = false;
      }

      if (ok)
        continue;

      temp++;
      rep(g, G) {
        group[g] = 0;
      }
      rep(i, H) {
        group[r2g[i]] += S[i][j];
      }
      ok = true;
      rep(g, G) {
        if (group[g] > K)
          ok = false;
      }
      if (!ok) {
        temp = INF;
        break;
      }
    }
    chmin(ans, temp);
  }
  cout << ans << endl;
}