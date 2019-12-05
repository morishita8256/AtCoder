#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

/*
  上に凸な関数fに対し
    argmax f(x)
  を返す

  ※凸関数でないとダメ
  　誤差で死にがち
 */
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

double find_min(double l, double r, double f(double)) {
  double cl = l + Golden * (r - l), cr = r - Golden * (r - l);
  double fc = f(cl), fd = f(cr);
  while (cr - cl > EPS) {
    if (fc > fd) {
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
https://yukicoder.me/problems/no/306
*/

double xa, ya;
double xb, yb;

double f(double y) {
  return sqrt(pow(xa, 2) + pow(ya - y, 2)) + sqrt(pow(xb, 2) + pow(yb - y, 2));
}

int main() {
  cin >> xa >> ya;
  cin >> xb >> yb;

  double ans = find_min(0.0, 1000.0, f);
  cout << setprecision(12) << ans << endl;
}