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
#define sz(x) ((ll)(x).size())
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

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

struct edge {
  ll to, cost;
  edge(ll to, ll cost) : to(to), cost(cost) {
  }
};

int V, E;
vector<vector<edge>> G;
vector<ll> dist;

typedef pair<ll, int> P;  // <最短距離, 頂点の番号>

/* 負閉路の検出はできない。O(E logV) */
/* 負の辺があってもダメ */
void dijkstra(int V, int E, vector<vector<edge>>& G, vector<ll>& dist, int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(dist.begin(), dist.end(), LINF);
  dist[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (dist[v] < p.first)
      continue;

    for (int i = 0; i < G[v].size(); ++i) {
      edge e = G[v][i];
      if (dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        que.push(P(dist[e.to], e.to));
      }
    }
  }
}

int main() {
  ll N, M;
  cin >> N >> M;
  vector<int> L(M), R(M), C(M);
  rep(i, M) {
    cin >> L[i] >> R[i] >> C[i];
    L[i]--, R[i]--;
  }

  int V, E;

  V = N, E = M;

  vector<vector<edge>> G(V);
  repr(i, V - 1, 1) {
    G[i].pb(edge(i - 1, 0));
  }
  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    from = L[i], to = R[i], cost = C[i];
    G[from].push_back(edge(to, cost));
  }
  vector<ll> dist(V);
  dijkstra(V, E, G, dist, 0);
  if (dist[V - 1] == LINF)
    cout << -1 << endl;
  else
    cout << dist[V - 1] << endl;
}