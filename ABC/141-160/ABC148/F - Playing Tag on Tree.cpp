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

struct edge {
  ll to, cost;
  edge(ll to, ll cost) : to(to), cost(cost) {
  }
};


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
  int N, u, v;
  cin >> N >> u >> v;
  u--, v--;
  vector<int> A(N - 1), B(N - 1);
  rep(i, N - 1) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }

  int V, E;

  V = N, E = N - 1;

  vector<vector<edge>> G(V);
  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    from = A[i], to = B[i], cost = 1;
    G[from].push_back(edge(to, cost));
    G[to].push_back(edge(from, cost));
  }
  vector<ll> dist_T(V);
  dijkstra(V, E, G, dist_T, u);
  vector<ll> dist_A(V);
  dijkstra(V, E, G, dist_A, v);

  ll ans = 0;
  rep(i, N) {
    if (dist_T[i] < dist_A[i])
      chmax(ans, dist_A[i]);
  }
  ans--;
  cout << ans << endl;
}