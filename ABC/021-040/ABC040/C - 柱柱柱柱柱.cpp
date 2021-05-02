#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
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
  int N;
  cin >> N;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];

  vector<ll> dp(N + 2, LINF);
  dp[0] = 0;
  rep(i, N - 1) {
    chmin(dp[i + 1], dp[i] + abs(a[i + 1] - a[i]));
    chmin(dp[i + 2], dp[i] + abs(a[i + 2] - a[i]));
  }
  cout << dp[N - 1] << endl;
}