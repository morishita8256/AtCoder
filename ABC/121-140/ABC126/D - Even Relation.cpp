#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

struct edge {
  int to, cost;
  edge(int to, int cost) : to(to), cost(cost) {}
};

void dfs(int now_ind, int now_color, int color[], vector<vector<edge>>& G) {
  for (auto e : G[now_ind]) {
    if (color[e.to] != -1) continue;
    int next_color;
    if (e.cost % 2 == 0) {
      next_color = now_color;
    } else {
      next_color = 1 - now_color;
    }
    color[e.to] = next_color;
    dfs(e.to, next_color, color, G);
  }
}

int main() {
  int N;
  cin >> N;

  vector<int> u(N - 1), v(N - 1), w(N - 1);
  rep(i, N - 1) {
    cin >> u[i] >> v[i] >> w[i];
    u[i]--;
    v[i]--;
  }

  vector<vector<edge>> G(N);

  rep(i, N - 1) {
    G[u[i]].pb(edge(v[i], w[i]));
    G[v[i]].pb(edge(u[i], w[i]));
  }

  int color[N];
  color[0] = 0;
  repp(i, 1, N - 1) { color[i] = -1; }
  dfs(0, 0, color, G);

  rep(i, N) { cout << color[i] << endl; }
}