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
  ll N = sz(S) + 1;
  reverse(all(S));
  S.pb('>');
  reverse(all(S));
  S.pb('<');

  vector<ll> a(N, -1);

  rep(i, N) {
    if (S[i] == '>' && S[i + 1] == '<')
      a[i] = 0;
  }

  repp(i, 1, N - 1) {
    if (S[i] == '<' && a[i - 1] != -1)
      chmax(a[i], a[i - 1] + 1);
  }

  repr(i, N - 2, 0) {
    if (S[i + 1] == '>' && a[i + 1] != -1)
      chmax(a[i], a[i + 1] + 1);
  }

  ll ans = 0;
  rep(i, N) {
    ans += a[i];
  }

  cout << ans << endl;

  // rep(i, N) {
  //   cout << a[i] << endl;
  // }
}