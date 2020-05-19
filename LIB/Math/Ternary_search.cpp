#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;

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
/*
  整数用の三分探索。

  凸関数fに対し
  argmax/min f
  を返す。

  ※凸関数になる初期値を渡さないとダメ。
 */

template <class T>
T find_max(T l, T r, T f(T)) {
  T cl, cr;
  while (r - l > 3) {
    cl = (l * 2 + r) / 3, cr = (l + r * 2) / 3;
    if (f(cl) < f(cr))
      l = cl;
    else
      r = cr;
  }

  T ans;
  T fmax = numeric_limits<T>::min();
  repp(i, l, r) {
    if (chmax(fmax, f(i)))
      ans = i;
  }
  return ans;
}

template <class T>
T find_min(T l, T r, T f(T)) {
  T cl, cr;
  while (r - l > 3) {
    cl = (l * 2 + r) / 3, cr = (l + r * 2) / 3;
    if (f(cl) > f(cr))
      l = cl;
    else
      r = cr;
  }

  T ans;
  T fmin = numeric_limits<T>::max();
  repp(i, l, r) {
    if (chmin(fmin, f(i)))
      ans = i;
  }
  return ans;
}

/*
https://yukicoder.me/problems/no/198
*/

vector<ll> C;
ll B, N;

ll f(ll x) {
  ll cnt = 0;
  ll num = 0;
  rep(i, N) {
    cnt += abs(C[i] - x);
    num += C[i];
  }

  if (num + B < x * N)
    cnt = LINF;
  return cnt;
}

int main() {
  cin >> B >> N;
  C = vector<ll>(N);

  rep(i, N) cin >> C[i];

  ll x = find_min(0LL, (ll)INF, f);
  cout << f(x) << endl;
}