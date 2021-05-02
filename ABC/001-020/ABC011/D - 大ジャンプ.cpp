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

#define double long double
typedef double ld;

int main() {
  ll N, D;
  cin >> N >> D;
  ll X, Y;
  cin >> X >> Y;

  X = abs(X);
  Y = abs(Y);

  if (X % D != 0 || Y % D != 0) {
    cout << 0 << endl;
    return 0;
  }

  ll x = X / D, y = Y / D;
  if (x + y > N) {
    cout << 0 << endl;
    return 0;
  }

  ll res = x + y - N;
  if (res % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  double ans = 0.0;
  repp(px, x, N) {
    repp(py, y, N) {
      int mx = px - x, my = py - y;
      if (px + py + mx + my != N)
        continue;
      // want to add (N!)/(px!py!mx!my!)*4^(-N) to ans
      double temp = 1.0;
      repp(i, 1, N) {
        temp *= (ld)i / 4.0;
      }
      repp(i, 1, px) {
        temp /= (ld)i;
      }
      repp(i, 1, py) {
        temp /= (ld)i;
      }
      repp(i, 1, mx) {
        temp /= (ld)i;
      }
      repp(i, 1, my) {
        temp /= (ld)i;
      }
      ans += temp;
    }
  }
  printf("%.14Lf\n", ans);  // Lf?
}