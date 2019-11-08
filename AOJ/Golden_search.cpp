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
double EPS = 1.0e-14;
const double Golden = 2.0 / (3.0 + sqrt(5));

double find_max(double l, double r, double f(double)) {
  double cl = l + Golden * (r - l), cr = r - Golden * (r - l);
  double fc = f(cl), fd = f(cr);
  while (cr - cl > EPS) {
    if (fc < fd) {
      l = cl;
      cl = cr;
      cr = r - Golden * (r - l);
      fc = fd;
      fd = f(cr);
    } else {
      r = cr;
      cr = cl;
      cl = l + Golden * (r - l);
      fd = fc;
      fc = f(cl);
    }
  }
  return (cl + cr) / 2.0;
}

/*
https://onlinejudge.u-aizu.ac.jp/problems/0323
*/
int N;
vector<double> x, r;

double f(double X) {
  double ans = LINF;
  rep(i, N) {
    double y = sqrt(pow(r[i], 2) - pow(x[i] - X, 2));
    chmin(ans, y);
  }
  return ans;
}

int main() {
  cin >> N;
  x = vector<double>(N);
  r = vector<double>(N);
  rep(i, N) cin >> x[i] >> r[i];

  double L = -LINF;
  double R = LINF;
  rep(i, N) {
    chmax(L, x[i] - r[i]);
    chmin(R, x[i] + r[i]);
  }

  double y = find_max(L, R, f);
  printf("%.14Lf\n", f(y));
}