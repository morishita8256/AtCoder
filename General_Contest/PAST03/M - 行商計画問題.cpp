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

#pragma region Dijkstra
struct edge {
  ll to, cost;
  edge(ll to, ll cost) : to(to), cost(cost) {
  }
};

typedef pair<ll, int> P;  // <最短距離, 頂点の番号>

void Dijkstra(int V, int E, vector<vector<edge>>& G, vector<ll>& dist, int s) {
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
#pragma endregion Dijkstra

int n;
vector<vector<int>> G;
vector<vector<int>> dp;
int rec(int S, int v) {
  if (dp[S][v] >= 0)
    return dp[S][v];

  if (S == bit(n) - 1 && v == 0)
    return dp[S][v] = 0;

  int res = INF;
  rep(u, n) {
    if (!(S >> u & 1))
      res = min(res, rec(S | bit(u), u) + G[v][u]);
  }

  return dp[S][v] = res;
}

signed main() {
  int N, M;
  cin >> N >> M;
  vector<int> u(M), v(M);
  vector<vector<edge>> GG(N);
  rep(i, M) {
    cin >> u[i] >> v[i];
    u[i]--, v[i]--;
    GG[u[i]].pb(edge(v[i], 1));
    GG[v[i]].pb(edge(u[i], 1));
  }

  int s, K;
  cin >> s >> K;
  s--;
  vector<int> t(K);
  rep(i, K) {
    cin >> t[i];
    t[i]--;
  }

  n = K + 1;
  G = vector<vector<int>>(n, vector<int>(n));
  rep(i, K) {
    vector<int> d(N);
    Dijkstra(N, M, GG, d, t[i]);
    rep(j, K) {
      G[i + 1][j + 1] = d[t[j]];
    }
  }

  dp = vector<vector<int>>(bit(n), vector<int>(n, -1));

  vector<int> ds(N);
  Dijkstra(N, M, GG, ds, s);
  rep(i, K) {
    G[0][i + 1] = ds[t[i]];
    G[i + 1][0] = ds[t[i]];
  }


  int ans = INF;
  rep(i, n) {
    chmin(ans, rec(0, i));
  }
  cout << ans << endl;
}