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
#define debug(var) cout << "[" << #var << "]\n" << var << "\n\n"
typedef long long ll;
const int INF = 1001001001;
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
      cout << '\n';
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

vector<vector<int>> G;
vector<bool> visited;

bool dfs(int from, int now) {
  if (visited[now])
    return false;
  visited[now] = true;

  if (len(G[now]) == 1 && G[now][0] == from)
    return true;

  bool ok = true;
  for (int next : G[now]) {
    if (next == from)
      continue;
    if (!dfs(now, next))
      ok = false;
  }
  return ok;
}


signed main() {
  int N, M;
  cin >> N >> M;
  vector<int> u(M), v(M);
  rep(i, M) {
    cin >> u[i] >> v[i];
    u[i]--, v[i]--;
  }

  G = vector<vector<int>>(N);
  rep(i, M) {
    G[u[i]].pb(v[i]);
    G[v[i]].pb(u[i]);
  }

  visited = vector<bool>(N);

  int ans = 0;
  rep(i, N) {
    if (visited[i])
      continue;
    if (dfs(-1, i))
      ans++;
  }
  cout << ans << "\n";
}