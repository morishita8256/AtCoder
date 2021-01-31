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

double A, B, C;

double f(double t) {
  return A * t + B * sin(C * t * M_PI) - 100;
}

int main() {
  cin >> A >> B >> C;
  double l = 0.0;
  double r = INF;
  while (abs(r - l) > 1e-12) {
    double m = (l + r) / 2.0;
    double F = f(m);
    if (F > 0)
      r = m;
    else
      l = m;
  }
  double ans = (l + r) / 2.0;
  printf("%.15f\n", ans);
}