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

int V, E;
vector<vector<edge>> G;
vector<ll> dist;

typedef pair<ll, int> P;  // <最短距離, 頂点の番号>

/* 負閉路の検出はできない。O(E logV) */
/* 負の辺があってもダメ */
void dijkstra(int s) {
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
  int N;
  cin >> N;
  vector<ll> a(N - 1), b(N - 1), c(N - 1);
  rep(i, N - 1) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }

  int Q, K;
  cin >> Q >> K;
  K--;
  vector<int> x(Q), y(Q);
  rep(i, Q) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }

  V = N;
  E = N - 1;
  G = vector<vector<edge>>(V);
  dist = vector<ll>(V);

  for (int i = 0; i < E; i++) {
    G[a[i]].pb(edge(b[i], c[i]));
    G[b[i]].pb(edge(a[i], c[i]));
  }

  dijkstra(K);
  rep(j, Q) {
    cout << dist[x[j]] + dist[y[j]] << endl;
  }
}