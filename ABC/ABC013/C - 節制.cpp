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
  ll N, H;
  cin >> N >> H;
  ll A, B, C;
  cin >> A >> B >> C;
  ll D, E;
  cin >> D >> E;

  ll ans = LINF;
  rep(i, N + 1) {
    ll manpuku = H + B * i;
    ll cost = A * i;

    ll day = N - i;
    ll j = (1 + day * E - manpuku + (D + E - 1)) / (D + E);

    if (j > day)
      continue;
    if (j < 0)
      j = 0;
    cost += C * j;
    chmin(ans, cost);
  }
  cout << ans << endl;
}