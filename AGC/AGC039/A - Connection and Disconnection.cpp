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
  string S;
  cin >> S;
  ll K;
  cin >> K;

  string S_cp = S;
  S_cp.pb('.');

  vector<ll> num;
  ll temp = 1;
  rep(i, sz(S)) {
    if (S_cp[i + 1] == S_cp[i])
      temp++;
    else {
      num.pb(temp);
      temp = 1;
    }
  }

  ll ans = 0;

  if (sz(num) == 1) {
    ans = (sz(S) * K) / 2;
  } else if (S[0] != S[sz(S) - 1]) {
    rep(i, sz(num)) {
      ans += K * (num[i] / 2);
    }
  } else {
    ans += num[0] / 2;
    repp(i, 1, sz(num) - 2) {
      ans += K * (num[i] / 2);
    }
    ans += (K - 1) * ((num[0] + num[sz(num) - 1]) / 2);
    ans += num[sz(num) - 1] / 2;
  }
  cout << ans << endl;
}