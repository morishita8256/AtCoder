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
  double a, b, x;
  cin >> a >> b >> x;

  double V = a * a * b;
  if (x <= V / 2) {
    double ans = atan(a * b * b / (2.0 * x)) / M_PI * 180.0;
    printf("%.14f\n", ans);
  } else {
    x = V - x;
    double ans = atan(2.0 * x / pow(a, 3)) / M_PI * 180.0;
    printf("%.14f\n", ans);
  }
}