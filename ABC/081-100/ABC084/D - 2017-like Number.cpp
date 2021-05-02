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

bool is_prime(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return n != 1;
}

int main() {
  int Q;
  cin >> Q;
  vector<int> l(Q), r(Q);
  rep(i, Q) cin >> l[i] >> r[i];

  vector<int> dp((int)1e+5 + 1);
  for (int i = 3; i <= (int)1e+5; i += 2) {
    dp[i] = dp[i - 2] + (is_prime(i) && is_prime((i + 1) / 2));
  }

  rep(i, Q) {
    int ans = dp[r[i]] - dp[max(0, l[i] - 2)];
    cout << ans << endl;
  }
}