#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1001001001001001001ll;

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
  int V, E;

  // V = , E = ;

  vector<vector<edge>> G(V);
  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    // from = , to = , cost = ;
    G[from].push_back(edge(to, cost));
    // G[to].push_back(edge(from, cost));
  }
  vector<ll> dist(V);
  dijkstra(V, E, G, dist, 0);

  for (int i = 0; i < V; i++) {
    if (dist[i] != LINF)
      cout << dist[i] << endl;
  }
}