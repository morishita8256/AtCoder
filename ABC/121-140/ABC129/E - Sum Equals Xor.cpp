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
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  string L;
  cin >> L;
  int N = L.size();

  ll ans = 0;
  ll num_of_one = 0;

  rep(i, N) {
    if (L[i] == '1') {
      ll temp = modpow(2, num_of_one, MOD);
      num_of_one++;
      ll res = N - 1 - i;
      temp *= modpow(3, res, MOD);
      temp %= MOD;
      ans += temp;
      ans %= MOD;
    }
  }
  ans += modpow(2, num_of_one, MOD);
  ans %= MOD;
  cout << ans << endl;
}