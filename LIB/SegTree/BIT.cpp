#include <bits/stdc++.h>
using namespace std;

/*
  ・デフォルトで1-indexedに注意
  ・セグ木より軽く、10^6の入力で 800ms, 4MB ほど
  ・左端からのsumについてのlower_boundも積んでいる
  ・printf, scanfを使う、ヘッダを軽くする、などもすべき
*/

#pragma region BIT

template <typename T>
struct BIT {
  int n;
  vector<T> bit;
  // 1-indexed
  BIT(int n_) : n(n_ + 1), bit(n + 1, 0) {
  }

  T sum(int i) {
    T s(0);
    for (int x = i; x > 0; x -= (x & -x))
      s += bit[x];
    return s;
  }

  void add(int i, T a) {
    if (i == 0)
      return;
    for (int x = i; x <= n; x += (x & -x))
      bit[x] += a;
  }

  // [l, r)
  T query(int l, int r) {
    return sum(r - 1) - sum(l - 1);
  }

  int lower_bound(int w) {
    if (w <= 0)
      return 0;
    int x = 0, r = 1;
    while (r < n)
      r <<= 1;
    for (int k = r; k > 0; k >>= 1) {
      if (x + k <= n && bit[x + k] < w) {
        w -= bit[x + k];
        x += k;
      }
    }
    return x + 1;
  }

  // 0-indexed
  T sum0(int i) {
    return sum(i + 1);
  }
  void add0(int i, T a) {
    add(i + 1, a);
  }
  T query0(int l, int r) {
    return sum(r) - sum(l);
  }
};
#pragma endregion

/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
*/

int main() {
  int n, q;
  cin >> n >> q;

  BIT<int> bt(n);
  while (q-- > 0) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0) {  // add
      bt.add(x, y);
    } else {  // get sum
      int sum = bt.query(x, y + 1);
      cout << sum << endl;
    }
  }
}