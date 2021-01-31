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
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M), c(M);
  rep(i, M) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--, b[i]--;
  }

  int V, E;
  V = N, E = M;

  vector<vector<edge>> G(V);
  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    from = a[i], to = b[i], cost = -c[i];
    G[from].push_back(edge(to, cost));
  }
  vector<ll> dist(V, LINF);  // ここを0にすると全ての負閉路が検出できる

  bellman_ford(V, E, G, dist, 0);
  ll ans_1 = -dist[N - 1];
  bellman_ford(V, E, G, dist, 0);
  ll ans_2 = -dist[N - 1];

  if (ans_1 == ans_2)
    cout << ans_1 << endl;
  else
    cout << "inf" << endl;
}
