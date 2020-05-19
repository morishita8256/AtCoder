#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1001001001001001001ll;

struct edge {
  ll to, cost;
  edge(ll to, ll cost) : to(to), cost(cost) {
  }
};

/* 負閉路があるとtrueを返す。O(EV) */
/* 負の辺があっても計算できる */
bool bellman_ford(int V,
                  int E,
                  vector<vector<edge>>& G,
                  vector<ll>& dist,
                  int s) {  // sは開始頂点
  dist[s] = 0;              // 開始点の距離は0
  for (int i = 0; i < V; i++) {
    for (int v = 0; v < V; v++) {
      for (int k = 0; k < G[v].size(); k++) {
        edge e = G[v][k];
        if (dist[v] != LINF && dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          if (i == V - 1)
            return true;  // n回目にも更新があるなら負の閉路が存在
        }
      }
    }
  }
  return false;
}

int main() {
  int V, E;
  // V =, E = ;

  vector<vector<edge>> G(V);
  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    // from =, to =, cost = ;
    G[from].push_back(edge(to, cost));
  }
  vector<ll> dist(V, LINF);  // ここを0にすると全ての負閉路が検出できる

  if (!bellman_ford(V, E, G, dist, 0))
    for (int i = 0; i < V; i++) {
      if (dist[i] != LINF)
        cout << dist[i] << endl;
    }
}