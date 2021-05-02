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

int main() {
  ll N;
  cin >> N;
  vector<string> S(N);
  rep(i, N) cin >> S[i];

  vector<ll> cnt(5, 0);
  string march = "MARCH";
  rep(i, N) {
    rep(j, 5) {
      if (S[i][0] == march[j]) cnt[j]++;
    }
  }

  ll ans = 0;
  rep(i, 1 << 5) {
    int cn = 0;
    ll temp = 1;
    rep(j, 5) {
      if (i >> j & 1) {
        cn++;
        temp *= cnt[j];
      }
    }
    if (cn == 3) {
      ans += temp;
    }
  }
  cout << ans << endl;
}