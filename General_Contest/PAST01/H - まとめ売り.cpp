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
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}


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
      : f(f), g(g), h(h), ti(ti), ei(ei) {
  }

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

signed main() {
  int N;
  cin >> N;
  vector<int> Co, Ce;
  rep(i, N) {
    int c;
    cin >> c;

    (i % 2 ? Co : Ce).pb(c);
  }

  int No = len(Co), Ne = len(Ce);


  // first:sum, second:# of including elem
  auto f = [](ll t1, ll t2) { return min(t1, t2); };
  auto ti = INT_MAX;
  auto g = [](ll t, ll e) { return t + e; };
  auto h = [](ll e1, ll e2) { return e1 + e2; };
  ll ei = 0;

  LazySegmentTree<ll, ll> Lo(f, g, h, ti, ei), Le(f, g, h, ti, ei);
  Lo.build(Co);
  Le.build(Ce);


  int Q;
  cin >> Q;

  int ans = 0;
  while (Q-- > 0) {
    int q;
    cin >> q;
    if (q == 1) {
      int x, a;
      cin >> x >> a;
      x--;

      auto L = (x % 2 ? &Lo : &Le);
      x /= 2;

      int stock = L->query(x, x + 1);
      if (stock < a)
        continue;
      L->update(x, x + 1, -a);
      ans += a;
    } else if (q == 2) {
      int a;
      cin >> a;

      int min_stock = Le.query(0, Ne);
      if (min_stock < a)
        continue;
      Le.update(0, Ne, -a);
      ans += Ne * a;
    } else {
      int a;
      cin >> a;

      int min_stock = min(Lo.query(0, No), Le.query(0, Ne));
      if (min_stock < a)
        continue;
      Lo.update(0, No, -a);
      Le.update(0, Ne, -a);
      ans += N * a;
    }
  }
  cout << ans << endl;
}