#pragma region head
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
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
#define int long long
typedef long long ll;
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

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
#pragma endregion

void dfs(int now, vector<vector<int>>& G, vector<bool>& visit) {
  visit[now] = true;
  for (int next : G[now])
    if (!visit[next])
      dfs(next, G, visit);
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


signed main() {
  int N, M, P;
  cin >> N >> M >> P;
  vector<int> A(M), B(M), C(M);

  vector<vector<int>> Gfw(N), Gbk(N);

  rep(i, M) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--, B[i]--;
    C[i] = P - C[i];

    Gfw[A[i]].pb(B[i]);
    Gbk[B[i]].pb(A[i]);
  }

  vector<bool> Fw(N, false), Bk(N, false);
  dfs(0, Gfw, Fw);
  dfs(N - 1, Gbk, Bk);

  vector<bool> use(N, false);
  rep(i, N) {
    if (Fw[i] && Bk[i])
      use[i] = true;
  }

  int V = 0;
  map<int, int> conv;
  rep(i, N) {
    if (use[i])
      conv[i] = V++;
  }

  vector<vector<edge>> G(V);
  int E = 0;
  rep(i, M) {
    if (use[A[i]] && use[B[i]]) {
      G[conv[A[i]]].pb(edge(conv[B[i]], C[i]));
      E++;
    }
  }

  int ans;
  vector<int> dist(V, INF);
  if (bellman_ford(V, E, G, dist, 0)) {
    ans = -1;
  } else {
    ans = -dist[V - 1];
    chmax(ans, 0ll);
  }

  cout << ans << endl;
}