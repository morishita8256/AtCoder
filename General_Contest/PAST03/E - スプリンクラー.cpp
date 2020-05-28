#pragma region head
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
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

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
#pragma endregion

void warshal_floyd(vector<vector<ll>>& dist) {
  int V = dist.size();
  rep(k, V) {
    rep(i, V) {
      rep(j, V) {
        // 負の辺のために必要なif文
        if (dist[i][k] != INF && dist[k][j] != INF)
          chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}


signed main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> u(M), v(M);
  rep(i, M) {
    cin >> u[i] >> v[i];
    u[i]--, v[i]--;
  }

  vector<vector<int>> dist(N, vector<int>(N, INF));
  rep(i, N) {
    dist[i][i] = 0;
  }
  rep(i, M) {
    dist[u[i]][v[i]] = 1;
    dist[v[i]][u[i]] = 1;
  }

  warshal_floyd(dist);

  vector<vector<int>> adj(N);
  rep(i, N) {
    rep(j, N) {
      if (dist[i][j] == 1)
        adj[i].pb(j);
    }
  }

  vector<int> c(N);
  rep(i, N) {
    cin >> c[i];
    c[i]--;
  }

  rep(_, Q) {
    int q;
    cin >> q;
    if (q == 1) {
      int x;
      cin >> x;
      x--;

      cout << (c[x] + 1) << endl;
      for (auto i : adj[x])
        c[i] = c[x];
    } else {
      int x, y;
      cin >> x >> y;
      x--, y--;
      cout << (c[x] + 1) << endl;
      c[x] = y;
    }
  }
}