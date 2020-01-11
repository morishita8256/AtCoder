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

int main() {
  ll N, K;
  cin >> N >> K;
  ll R, S, P;
  cin >> R >> S >> P;
  string T;
  cin >> T;

  map<char, ll> m;
  m['s'] = R, m['p'] = S, m['r'] = P;

  vector<string> group(K);
  rep(i, N) {
    group[i % K].pb(T[i]);
  }

  ll ans = 0;
  rep(i, K) {
    rep(j, sz(group[i])) {
      ans += m[group[i][j]];
      if (j + 1 < sz(group[i]) && group[i][j] == group[i][j + 1])
        j++;
    }
  }
  cout << ans << endl;
}