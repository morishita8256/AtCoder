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
  ll N, M, T;
  cin >> N >> M >> T;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<ll> a(M), b(M), c(M);
  rep(i, M) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }

  int V = N;
  int E = M;

  vector<vector<edge>> G1(V);
  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    from = a[i];
    to = b[i];
    cost = c[i];
    G1[from].push_back(edge(to, cost));
  }
  vector<ll> dist1(V);
  dijkstra(V, E, G1, dist1, 0);

  vector<vector<edge>> G2(V);
  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    from = b[i];
    to = a[i];
    cost = c[i];
    G2[from].push_back(edge(to, cost));
  }
  vector<ll> dist2(V);
  dijkstra(V, E, G2, dist2, 0);

  ll ans = 0;
  for (int i = 0; i < V; i++) {
    ll time = T - (dist1[i] + dist2[i]);
    if (dist1[i] == LINF || dist2[i] == LINF)
      continue;
    ll money = A[i] * time;
    chmax(ans, money);
  }

  cout << ans << endl;
}
