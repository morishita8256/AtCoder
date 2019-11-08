#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

/*
  O(FE)

  初期化
  Ford_Fulkerson<int> g(V);

  辺の追加
  add_edge(from, to, cap);

  最大流
  max_flow(s, t);

  ※Fの大きさに注意。
*/
template <typename flow_t>
struct Ford_Fulkerson {
  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  vector<vector<edge> > graph;
  vector<int> used;
  const flow_t INF_flow_t;
  int timestamp;

  Ford_Fulkerson(int n)
      : INF_flow_t(numeric_limits<flow_t>::max()), timestamp(0) {
    graph.resize(n);
    used.assign(n, -1);
  }

  void add_edge(int from, int to, flow_t cap, int idx = -1) {
    graph[from].emplace_back(
        (edge){to, cap, (int)graph[to].size(), false, idx});
    graph[to].emplace_back(
        (edge){from, 0, (int)graph[from].size() - 1, true, idx});
  }

  flow_t dfs(int idx, const int t, flow_t flow) {
    if (idx == t)
      return flow;
    used[idx] = timestamp;
    for (auto& e : graph[idx]) {
      if (e.cap > 0 && used[e.to] != timestamp) {
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
    for (flow_t f; (f = dfs(s, t, INF_flow_t)) > 0; timestamp++) {
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
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=ja
*/
int main() {
  int X, Y, E;
  cin >> X >> Y >> E;
  vector<int> x(E), y(E);

  /*
    X: 0 ... X-1
    Y: X ... X+Y-1
    s: X+Y
    t: X+Y+1
  */
  rep(i, E) {
    cin >> x[i] >> y[i];
    y[i] += X;
  }

  int N = X + Y + 2;
  int s = X + Y, t = s + 1;

  Ford_Fulkerson<int> g(N);
  rep(i, X) {
    g.add_edge(s, i, 1);  // not x[i]
  }
  rep(i, Y) {
    g.add_edge(X + i, t, 1);  // not y[i]
  }
  rep(i, E) {
    g.add_edge(x[i], y[i], 1);
  }

  cout << g.max_flow(s, t) << endl;
}