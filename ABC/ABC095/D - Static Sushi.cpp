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
  ll N, C;
  cin >> N >> C;
  vector<ll> x(N + 2), v(N + 2);
  x[0] = v[0] = 0;
  x[N + 1] = C;
  v[N + 1] = 0;
  repp(i, 1, N) cin >> x[i] >> v[i];

  vector<ll> cl(N + 2);
  ll temp = 0;
  repp(i, 0, N + 1) {
    temp += v[i];
    cl[i] = temp - x[i];
  }
  repp(i, 1, N + 1) {
    chmax(cl[i], cl[i - 1]);
  }

  vector<ll> acl(N + 2);
  temp = 0;
  repr(i, N + 1, 0) {
    temp += v[i];
    acl[i] = temp - (C - x[i]);
  }
  repr(i, N, 0) {
    chmax(acl[i], acl[i + 1]);
  }

  ll ans = 0;

  repp(i, 0, N) {
    ll temp = cl[i] + acl[i + 1];
    chmax(ans, temp - min(x[i], C - x[i + 1]));
  }

  cout << ans << endl;
}