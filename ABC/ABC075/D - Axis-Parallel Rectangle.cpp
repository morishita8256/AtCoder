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
const ll LINF = 1ll << 62;
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
  int N, K;
  cin >> N >> K;
  vector<ll> x(N), y(N);
  rep(i, N) cin >> x[i] >> y[i];

  vector<ll> xx = x;
  vector<ll> yy = y;
  sort(all(xx));
  sort(all(yy));

  ll ans = LINF;
  repp(xi, 0, N - 2) {
    repp(xj, xi + 1, N - 1) {
      repp(yi, 0, N - 2) {
        repp(yj, yi + 1, N - 1) {
          ll l = xx[xi];
          ll r = xx[xj];
          ll d = yy[yi];
          ll u = yy[yj];
          int cnt = 0;
          rep(k, N) {
            if (l <= x[k] && x[k] <= r && d <= y[k] && y[k] <= u)
              cnt++;
          }
          if (cnt >= K)
            chmin(ans, (r - l) * (u - d));
        }
      }
    }
  }
  cout << ans << endl;
}