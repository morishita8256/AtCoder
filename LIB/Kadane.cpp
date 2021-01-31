#pragma region head
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001001001001ll;

/*
  最大部分配列問題。O(N)。
*/
template <typename T>
T Kadane(vector<T> as) {
  T res = -INF;
  T s = 0;
  for (T elem : as) {
    s = max(s + elem, elem);
    res = max(res, s);
  }
  return res;
}


/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0022
*/

signed main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      return 0;

    vector<int> a(n);
    rep(i, n) {
      cin >> a[i];
    }

    int ans = Kadane(a);
    cout << ans << endl;
  }
}