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
  int to, cost;
  edge(int to, int cost) : to(to), cost(cost) {}
};

int V;
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
  int N, M;
  cin >> N >> M;

  vector<int> a(M), b(M);
  int V = bit(N);
  G = vector<vector<edge>>(V);

  vector<vector<int>> c(M);
  int temp;
  rep(i, M) {
    cin >> a[i] >> b[i];
    int key_comb = 0;
    rep(j, b[i]) {
      int temp;
      cin >> temp;
      c[i].pb(temp);
      key_comb |= bit(temp - 1);
    }

    rep(now, V) {
      int next = now | key_comb;
      if (next != now) {
        G[now].pb(edge(next, a[i]));
      }
    }
  }

  dist = vector<ll>(V);
  dijkstra(0);
  ll ans = dist[bit(N) - 1];
  if (ans == LINF)
    ans = -1;
  cout << ans << endl;
}