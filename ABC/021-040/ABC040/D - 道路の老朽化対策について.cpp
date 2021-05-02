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


struct road {
  int a, b, y;
  road(int a, int b, int y) : a(a), b(b), y(y) {
  }

  bool operator<(const road& another) const {
    return y > another.y;
  };
};

struct person {
  int id, city, year;
  person(int id, int city, int year) : id(id), city(city), year(year) {
  }

  bool operator<(const person& another) const {
    return year > another.year;
  };
};

bool cmp(const person& a, const person& b) {
  return a.year > b.year;
}


/* O(log n) */
struct UnionFind {
  vector<int> parent;  // parent[root] is the negative of the size.
  UnionFind(int n) : parent(n, -1){};
  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v)
      return false;
    if (parent[u] > parent[v])
      swap(u, v);
    parent[u] += parent[v];
    parent[v] = u;
    return true;
  }
  bool issame(int u, int v) {
    return root(u) == root(v);
  }
  int root(int u) {
    return parent[u] < 0 ? u : parent[u] = root(parent[u]);
  }
  int size(int u) {
    return -parent[root(u)];
  }
};


int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M), y(M);
  rep(i, M) {
    cin >> a[i] >> b[i] >> y[i];
    a[i]--;
    b[i]--;
  }
  int Q;
  cin >> Q;
  vector<int> v(Q), w(Q);
  rep(i, Q) {
    cin >> v[i] >> w[i];
    v[i]--;
  }

  vector<road> r;
  rep(i, M) {
    r.pb(road(a[i], b[i], y[i]));
  }

  vector<person> p;
  rep(i, Q) {
    p.pb(person(i, v[i], w[i]));
  }

  sort(all(r));
  sort(all(p), cmp);
  vector<int> ans(Q);

  UnionFind u(N);
  int ind = 0;
  rep(i, Q) {
    while (r[ind].y > p[i].year) {
      u.unite(r[ind].a, r[ind].b);
      ind++;
      if (ind == M)
        break;
    }
    int temp = u.size(p[i].city);
    ans[p[i].id] = temp;
  }

  rep(i, Q) {
    cout << ans[i] << endl;
  }
}