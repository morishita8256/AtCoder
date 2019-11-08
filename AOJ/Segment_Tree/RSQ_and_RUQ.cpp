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
#define sz(x) ((int)(x).size())
typedef long long ll;

template <typename T, typename E>
struct LazySegmentTree {
  using F = function<T(T, T)>;
  using G = function<T(T, E)>;
  using H = function<E(E, E)>;
  int n, height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  LazySegmentTree(F f, G g, H h, T ti, E ei)
      : f(f), g(g), h(h), ti(ti), ei(ei) {}

  void init(int n_) {
    n = 1;
    height = 0;
    while (n < n_)
      n <<= 1, height++;
    dat.assign(2 * n, ti);
    laz.assign(2 * n, ei);
  }
  void build(const vector<T>& v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++)
      dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }
  inline T reflect(int k) {
    return laz[k] == ei ? dat[k] : g(dat[k], laz[k]);
  }
  inline void eval(int k) {
    if (laz[k] == ei)
      return;
    laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = ei;
  }
  inline void thrust(int k) {
    for (int i = height; i; i--)
      eval(k >> i);
  }
  inline void recalc(int k) {
    while (k >>= 1)
      dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }
  void update(int a, int b, E x) {
    thrust(a += n);
    thrust(b += n - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        laz[l] = h(laz[l], x), l++;
      if (r & 1)
        --r, laz[r] = h(laz[r], x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a, T x) {
    thrust(a += n);
    dat[a] = x;
    laz[a] = ei;
    recalc(a);
  }
  T query(int a, int b) {
    thrust(a += n);
    thrust(b += n - 1);
    T vl = ti, vr = ti;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        vl = f(vl, reflect(l++));
      if (r & 1)
        vr = f(reflect(--r), vr);
    }
    return f(vl, vr);
  }

  template <typename C>
  int find(int st, C& check, T& acc, int k, int l, int r) {
    if (l + 1 == r) {
      acc = f(acc, reflect(k));
      return check(acc) ? k - n : -1;
    }
    eval(k);
    int m = (l + r) >> 1;
    if (m <= st)
      return find(st, check, acc, (k << 1) | 1, m, r);
    if (st <= l && !check(f(acc, dat[k]))) {
      acc = f(acc, dat[k]);
      return -1;
    }
    int vl = find(st, check, acc, (k << 1) | 0, l, m);
    if (~vl)
      return vl;
    return find(st, check, acc, (k << 1) | 1, m, r);
  }
  template <typename C>
  int find(int st, C& check) {
    T acc = ti;
    return find(st, check, acc, 1, 0, n);
  }
};

/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
*/
int main() {
  int n, q;
  cin >> n >> q;

  using P = pair<ll, ll>;
  // first:sum, second:# of including elem
  auto f = [](P t1, P t2) { return P(t1.fi + t2.fi, t1.se + t2.se); };
  auto ti = P(0, 0);
  auto g = [](P t, ll e) {
    if (e == -1010)
      return t;
    else
      return P(t.se * e, t.se);
  };
  auto h = [](ll e1, ll e2) {
    if (e2 == -1010)
      return e1;
    else
      return e2;
  };
  ll ei = -1010;

  LazySegmentTree<P, ll> lz(f, g, h, ti, ei);
  lz.build(vector<P>(n, P(0, 1)));

  vector<ll> ans;
  rep(Q, q) {
    int query;
    cin >> query;
    if (query == 0) {
      ll s, t, x;
      cin >> s >> t >> x;
      lz.update(s, t + 1, x);
    } else {
      ll s, t;
      cin >> s >> t;
      ans.pb(lz.query(s, t + 1).fi);
    }
  }

  rep(i, ans.size()) {
    cout << ans[i] << endl;
  }
}
