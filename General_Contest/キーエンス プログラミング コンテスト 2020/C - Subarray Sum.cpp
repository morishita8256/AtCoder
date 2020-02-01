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
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

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
  ll N, K, S;
  cin >> N >> K >> S;

  ll mx = 1000000000;
  if (S < mx) {
    vector<ll> ans(N, mx);
    rep(i, K) {
      ans[i] = S;
    }
    rep(i, len(ans)) {
      cout << ans[i] << ((i == len(ans) - 1) ? "\n" : " ");
    }
    return 0;
  } else {
    vector<ll> ans(N, 1);
    rep(i, K) {
      ans[i] = S;
    }
    rep(i, len(ans)) {
      cout << ans[i] << ((i == len(ans) - 1) ? "\n" : " ");
    }
  }
}