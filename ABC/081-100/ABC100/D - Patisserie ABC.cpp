#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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
  int N, M;
  cin >> N >> M;
  vector<ll> x(N), y(N), z(N);
  rep(i, N) cin >> x[i] >> y[i] >> z[i];

  vector<vector<ll>> s(8, vector<ll>(N));
  rep(j, bit(3)) {
    rep(i, N) {
      ll xsign = ((j >> 0) & 1) ? 1 : -1;
      ll ysign = ((j >> 1) & 1) ? 1 : -1;
      ll zsign = ((j >> 2) & 1) ? 1 : -1;
      s[j][i] = x[i] * xsign + y[i] * ysign + z[i] * zsign;
    }
  }
  ll ans = -LINF;
  rep(j, 8) {
    sort(all(s[j]), greater<ll>());
    ll temp = 0;
    rep(i, M) {
      temp += s[j][i];
    }
    chmax(ans, temp);
  }
  cout << ans << endl;
}