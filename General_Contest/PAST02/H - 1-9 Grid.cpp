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
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}


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


signed main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  rep(i, N) {
    rep(j, M) {
      char c;
      cin >> c;
      if (c == 'S')
        A[i][j] = 0;
      else if (c == 'G')
        A[i][j] = 10;
      else
        A[i][j] = c - '0';
    }
  }

  vector<vector<int>> num2v(11);
  rep(i, N) {
    rep(j, M) {
      int v = i * M + j;
      num2v[A[i][j]].pb(v);
    }
  }

  int V = N * M;
  int E = 0;
  vector<vector<edge>> G(V);
  rep(i, 10) {
    for (int vl : num2v[i]) {
      for (int vh : num2v[i + 1]) {
        int il = vl / M, jl = vl % M;
        int ih = vh / M, jh = vh % M;
        int cost = abs(il - ih) + abs(jl - jh);
        G[vl].pb(edge(vh, cost));
        E++;
      }
    }
  }

  vector<int> dist(V);
  dijkstra(V, E, G, dist, num2v[0][0]);

  int ans = dist[num2v[10][0]];
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
}