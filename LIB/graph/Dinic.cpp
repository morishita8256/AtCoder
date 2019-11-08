#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

/*
  最大流
  O(EV^2) ※大抵はもっと速い

  初期化
  Ford_Fulkerson<int> g(V);

  辺の追加
  g.add_edge(from, to, cap);

  最大流
  g.max_flow(s, t);
*/

template <typename flow_t>
struct Dinic {
  const flow_t INF_flow_t;

  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  vector<vector<edge> > graph;
  vector<int> min_cost, iter;

  Dinic(int V) : INF_flow_t(numeric_limits<flow_t>::max()), graph(V) {}

  void add_edge(int from, int to, flow_t cap, int idx = -1) {
    graph[from].emplace_back(
        (edge){to, cap, (int)graph[to].size(), false, idx});
    graph[to].emplace_back(
        (edge){from, 0, (int)graph[from].size() - 1, true, idx});
  }

  bool bfs(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue<int> que;
    min_cost[s] = 0;
    que.push(s);
    while (!que.empty() && min_cost[t] == -1) {
      int p = que.front();
      que.pop();
      for (auto& e : graph[p]) {
        if (e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  flow_t dfs(int idx, const int t, flow_t flow) {
    if (idx == t)
      return flow;
    for (int& i = iter[idx]; i < graph[idx].size(); i++) {
      edge& e = graph[idx][i];
      if (e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if (d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s, int t) {
    flow_t flow = 0;
    while (bfs(s, t)) {
      iter.assign(graph.size(), 0);
      flow_t f = 0;
      while ((f = dfs(s, t, INF_flow_t)) > 0)
        flow += f;
    }
    return flow;
  }

  void output() {
    for (int i = 0; i < graph.size(); i++) {
      for (auto& e : graph[i]) {
        if (e.isrev)
          continue;
        auto& rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/"
             << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};

/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja
*/

int main() {
  int V, E;
  cin >> V >> E;
  vector<int> u(E), v(E), c(E);
  rep(i, E) cin >> u[i] >> v[i] >> c[i];

  Dinic<int> g(V);
  rep(i, E) {
    g.add_edge(u[i], v[i], c[i]);
  }
  cout << g.max_flow(0, V - 1) << endl;
}