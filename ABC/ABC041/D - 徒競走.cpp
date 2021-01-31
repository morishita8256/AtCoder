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
  int N, M;
  cin >> N >> M;
  vector<int> x(M), y(M);
  vector<vector<int>> G(N);
  vector<int> IN(N);
  rep(i, M) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;

    G[x[i]].pb(y[i]);
    IN[y[i]]++;
  }

  int B = bit(N);
  vector<int> dp(B);
  dp[0] = 1;

  rep(b, B) {
    auto in = IN;
    rep(i, N) {
      if (bit(i) & b) {
        for (int to : G[i])
          in[to]--;
      }
    }

    rep(i, N) {
      if (in[i] == 0 && !(bit(i) & b)) {
        int nb = b | (bit(i));
        dp[nb] += dp[b];
      }
    }
  }

  int ans = dp[B - 1];
  cout << ans << endl;
}