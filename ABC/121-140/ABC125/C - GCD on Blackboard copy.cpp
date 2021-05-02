#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
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

template <typename T>
struct SegmentTree {
  using F = function<T(T, T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f, T ti) : f(f), ti(ti) {}

  void init(int n_) {
    n = 1;
    while (n < n_)
      n <<= 1;
    dat.assign(n << 1, ti);
  }

  void build(const vector<T>& v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++)
      dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }

  void set_val(int k, T x) {
    dat[k += n] = x;
    while (k >>= 1)
      dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
  }

  // [a, b)
  T query(int a, int b) {
    T vl = ti, vr = ti;
    for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        vl = f(vl, dat[l++]);
      if (r & 1)
        vr = f(dat[--r], vr);
    }
    return f(vl, vr);
  }
};

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  auto f = [](ll a, ll b) {
    if (b == 0)
      return a;
    else
      return gcd(a, b);
  };
  SegmentTree<ll> seg(f, 0);
  seg.build(A);

  ll ans = 0;
  rep(i, N) {
    ll l = seg.query(0, i);
    ll r = seg.query(i + 1, N);
    chmax(ans, gcd(l, r));
  }
  cout << ans << endl;
}