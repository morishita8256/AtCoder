#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1001001001001001001ll;

struct edge {
  ll to, cost;
  edge(ll to, ll cost) : to(to), cost(cost) {}
};

int V, E;
vector<vector<edge>> G;
vector<ll> dist;

/* 負閉路があるとtrueを返す。O(EV) */
/* 負の辺があっても計算できる */
bool bellman_ford(int s) {  // sは開始頂点
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
  cin >> V >> E;
  G = vector<vector<edge>>(V);
  dist = vector<ll>(V, LINF);  // ここを0にすると全ての負閉路が検出できる

  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    cin >> from >> to >> cost;
    from--;
    to--;
    G[from].push_back(edge(to, cost));
  }

  if (!bellman_ford(0))
    for (int i = 0; i < V; i++) {
      cout << dist[i] << endl;
    }
}