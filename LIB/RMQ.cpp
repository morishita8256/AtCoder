#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll LINF = ((ll)1 << 31) - 1;

struct SegmentTree {
  int n, n0;
  vector<ll> data;

  SegmentTree(int n) {
    data = vector<ll>(4 * n);
    n0 = 1;
    while (n0 < n)
      n0 <<= 1;
    for (int i = 0; i < 2 * n0; i++) {
      data[i] = LINF;
    }
  }

  void update(int k, ll x) {
    k += n0 - 1;
    data[k] = x;
    while (k > 0) {
      k = (k - 1) / 2;
      data[k] = min(data[2 * k + 1], data[2 * k + 2]);
    }
  }

  ll __query(int a, int b, int k, int l, int r) {
    if (a <= l && r <= b) {
      return data[k];
    }
    if (r <= a || b <= l) {
      return LINF;
    }
    ll lv = __query(a, b, 2 * k + 1, l, (l + r) / 2);
    ll rv = __query(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(lv, rv);
  }

  ll query(int a, int b) {
    return __query(a, b, 0, 0, n0);
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  SegmentTree st(n);
  for (int i = 0; i < q; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    switch (t) {
      case 0:
        st.update(x, y);
        break;
      case 1:
        cout << st.query(x, y + 1) << endl;
        break;
    }
  }
}