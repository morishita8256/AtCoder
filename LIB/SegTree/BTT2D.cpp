#include <bits/stdc++.h>
using namespace std;
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define int long long
typedef long long ll;

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
}

inline ll randll() {
  ll x = rand();
  x = (x << 12) | rand();
  x = (x << 12) | rand();
  x = (x << 12) | rand();
  return x;
}

#pragma region BIT2D
template <typename T>
struct BIT2D {
  int n, m;
  T d;
  vector<vector<T> > bit;

  // 1-indexed
  BIT2D() : n(-1), m(-1) {
  }

  BIT2D(int n_, int m_) : n(n_), m(m_), bit(n_ + 1, vector<T>(m + 1, 0)) {
  }

  T sum(int i, int j) {
    T s(0);
    for (int x = i; x > 0; x -= (x & -x))
      for (int y = j; y > 0; y -= (y & -y))
        s += bit[x][y];
    return s;
  }

  void add(int i, int j, T a) {
    if (i == 0 || j == 0)
      return;
    for (int x = i; x <= n; x += (x & -x))
      for (int y = j; y <= m; y += (y & -y))
        bit[x][y] += a;
  }

  // [x1,x2] * [y1,y2];
  T sum(int x1, int y1, int x2, int y2) {
    return sum(x1 - 1, y1 - 1) - sum(x1 - 1, y2) - sum(x2, y1 - 1) +
           sum(x2, y2);
  }
};
#pragma endregion BIT2D


/*
  https://codeforces.com/problemset/problem/869/E
*/

signed main() {
  srand(time(NULL));
  int n, m, q;
  cin >> n >> m >> q;
  typedef pair<int, int> P;

  BIT2D<int> bt(n, m);
  map<P, int> mp;

  while (q-- > 0) {
    int t;
    cin >> t;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    if (t == 1) {  // place, remove
      r2++, c2++;
      P pos(r1 * m + c1, r2 * m + c2);
      int k = randll();
      mp[pos] = k;

      bt.add(r1, c1, k);
      bt.add(r2, c2, k);
      bt.add(r1, c2, -k);
      bt.add(r2, c1, -k);

    } else if (t == 2) {
      r2++, c2++;
      P pos(r1 * m + c1, r2 * m + c2);
      int k = -mp[pos];
      bt.add(r1, c1, k);
      bt.add(r2, c2, k);
      bt.add(r1, c2, -k);
      bt.add(r2, c1, -k);

    } else {  // query
      bool ok = (bt.sum(r1, c1) == bt.sum(r2, c2));
      if (ok)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
}