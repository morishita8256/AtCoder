#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define int long long
typedef long long ll;
#define double long double
typedef double ld;
const double EPS = 1e-10;

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

/*
  凸関数fに対し
    argmax f(x)
  を返す

  ※凸関数でないとダメ
  　誤差で死にがち
  　極値を挟んだ値を渡していることを確認
 */

#pragma region golden_search
const double Golden = 2.0 / (3.0 + sqrt(5));
double f(double trial);

double golden_search(double l, double r) {
  bool isMax = (f((ld)l - 1e-2) < f((ld)l));
  int cnt = 100;
  double cl = l + Golden * (r - l), cr = r - Golden * (r - l);
  double fc = f(cl), fd = f(cr);
  while (cr - cl > EPS && cnt-- > 0) {
    if (isMax ? (fc < fd) : (fc > fd)) {
      l = cl, cl = cr, cr = r - Golden * (r - l);
      fc = fd, fd = f(cr);
    } else {
      r = cr, cr = cl, cl = l + Golden * (r - l);
      fd = fc, fc = f(cl);
    }
  }
  return (cl + cr) / 2.0;
}
#pragma endregion

/*
https://atcoder.jp/contests/arc054/tasks/arc054_b
*/

double P;
double f(double trial) {
  return trial + P * pow(2, -trial / 1.5);
}

signed main() {
  cin >> P;
  double x = golden_search((ld)-100.0, (ld)100.0);
  if (x < 0)
    x = 0;
  cout << f(x) << endl;
}