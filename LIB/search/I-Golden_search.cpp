#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define int long long
typedef long long ll;
#define double long double
typedef double ld;
const double EPS = 1e-9;

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

template <typename T>
T f(T trial);

int golden_search(int l, int r) {
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

  int c1 = (cl + cr) / 2.0, c2 = c1 + 1;
  int ans = !(isMax ^ (f(c1) > f(c2))) ? c1 : c2;
  return ans;
}
#pragma endregion

int B, N;
vector<int> C;
template <typename T>
T f(T trial) {
  T cnt = 0;
  rep(i, N) {
    cnt += abs(trial - C[i]);
  }
  return cnt;
}

/*
https://yukicoder.me/problems/no/198
*/

signed main() {
  cin >> B >> N;
  C = vector<int>(N);
  int mx = B;
  rep(i, N) {
    cin >> C[i];
    mx += C[i];
  }
  mx /= N;


  int c = golden_search(0ll, mx);
  int ans = f(c);
  cout << ans << endl;
}