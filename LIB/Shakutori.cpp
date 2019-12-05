#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;


/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C&lang=jp
*/

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<ll> a(N);
  rep(i, N) {
    cin >> a[i];
  }
  vector<ll> x(Q);
  rep(i, Q) {
    cin >> x[i];
  }

  rep(q, Q) {
    ll ans = 0;
    ll sum = 0;
    int r = 0;
    rep(l, N) {
      while (r < N && sum + a[r] <= x[q]) {
        sum += a[r];
        ++r;
      }

      /* break した状態で r は条件を満たす最大なので、何かする */
      ans += (r - l);

      /* l をインクリメントする準備 */
      if (r == l)
        ++r;
      else
        sum -= a[l];
    }
    cout << ans << endl;
  }
}