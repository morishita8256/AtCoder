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

int Smax = 2500;
int toV(int ind, int s) {
  return ind * (Smax + 1) + s;
}

signed main() {
  int N, M, S;
  cin >> N >> M >> S;

  chmin(S, Smax);

  vector<int> U(M), V(M), A(M), B(M);
  rep(i, M) {
    cin >> U[i] >> V[i] >> A[i] >> B[i];
    U[i]--, V[i]--;
  }
  vector<int> C(N), D(N);
  rep(i, N) {
    cin >> C[i] >> D[i];
  }

  int Ver = N * (Smax + 1);
  int E = 0;
  vector<vector<edge>> G(Ver);
  rep(i, M) {
    repp(s, 0, Smax) {
      int ns = s - A[i];
      if (ns < 0)
        continue;
      G[toV(U[i], s)].pb(edge(toV(V[i], ns), B[i]));
      G[toV(V[i], s)].pb(edge(toV(U[i], ns), B[i]));
      E += 2;
    }
  }
  rep(i, N) {
    repp(s, 0, Smax) {
      int ns = s + C[i];
      if (ns > Smax)
        continue;
      G[toV(i, s)].pb(edge(toV(i, ns), D[i]));
      E++;
    }
  }

  vector<int> dist(Ver);
  int s = toV(0, S);
  dijkstra(Ver, E, G, dist, s);

  vector<int> ans(N - 1);
  rep(i, N - 1) {
    int g = i + 1;
    int mn = INF;
    repp(j, toV(g, 0), toV(g, Smax)) {
      chmin(mn, dist[j]);
    }
    ans[i] = mn;
  }

  rep(i, len(ans)) {
    cout << ans[i] << endl;
  }
}