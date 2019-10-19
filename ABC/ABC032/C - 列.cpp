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
#define sz(x) ((int)(x).size())
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
  vector<ll> s(N);
  rep(i, N) cin >> s[i];

  rep(i, N) {
    if (s[i] == 0) {
      cout << N << endl;
      return 0;
    }
  }

  ll temp = 1;
  int l = 0, r = 0;
  int ans = 0;
  rep(l, N) {
    while (temp * s[r] <= K && r < N) {
      temp *= s[r++];
    }
    chmax(ans, r - l);
    if (r == l)
      r++;
    else
      temp /= s[l];
  }
  cout << ans << endl;
}