#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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

struct edge {
  ll to, cost;
  edge(ll to, ll cost) : to(to), cost(cost) {}
};

int V, E, P;
vector<vector<edge>> G;
vector<ll> dist;

/* 負閉路があるとtrueを返す。O(EV) */
/* 負の辺があっても計算できる */
bool bellman_ford(int s, vector<ll>& dist, int iter) {  // sは開始頂点
  dist[s] = 0;  // 開始点の距離は0
  for (int i = 0; i < iter; i++) {
    for (int v = 0; v < V; v++) {
      for (int k = 0; k < G[v].size(); k++) {
        edge e = G[v][k];
        if (dist[v] != LINF && dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
        }
      }
    }
  }
}

void dfs(int now, vector<vector<edge>>& G, vector<bool>& reach) {
  reach[now] = true;
  for (auto edge : G[now]) {
    ll next = edge.to;
    if (reach[next])
      continue;
    dfs(next, G, reach);
  }
}

int main() {
  cin >> V >> E >> P;

  vector<vector<edge>> Gf(V);
  vector<bool> reachf(V, false);
  vector<vector<edge>> Gb(V);
  vector<bool> reachb(V, false);

  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    cin >> from >> to >> cost;
    from--;
    to--;
    Gf[from].push_back(edge(to, P - cost));
    Gb[to].push_back(edge(from, P - cost));
  }

  dfs(0, Gf, reachf);
  dfs(V - 1, Gb, reachb);

  vector<bool> use(V);
  rep(i, V) {
    use[i] = (reachf[i] && reachb[i]);
  }

  G = vector<vector<edge>>(V);

  rep(i, V) {
    if (!use[i])
      continue;
    for (auto ed : Gf[i]) {
      if (use[ed.to]) {
        G[i].pb(edge(ed.to, ed.cost));
      }
    }
  }

  vector<ll> dist1(V, LINF);
  bellman_ford(0, dist1, V);

  vector<ll> dist2(V, LINF);
  bellman_ford(0, dist2, 2 * V);

  bool ok = true;
  rep(i, V) {
    if (dist1[i] != dist2[i])
      ok = false;
  }

  if (ok) {
    cout << max(0LL, -dist1[V - 1]) << endl;
  } else {
    cout << -1 << endl;
  }
}