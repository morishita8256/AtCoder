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


/*
  巡回セールスマン問題。O(N*2^N)。N<=20くらいが限度。
  TravelingSalesman(dist, start, goal);
  distは隣接行列。startから全ての頂点を1度ずつ通ってgoalまで行くときの最短距離を返す。start=goalの場合はサイクルになる。

  start!=goalの場合は初期状態でstartを訪問済みにするひつようがある。これは変数ISで表している。
*/

template <typename T>
T rec(int s, int v, int goal, vector<vector<T>>& dist, vector<vector<T>>& dp) {
  int V = dist.size(), S = dp.size();
  if (dp[s][v] >= 0)
    return dp[s][v];
  if (s == S - 1 && v == goal)
    return dp[s][v] = 0;

  int res = INF;
  rep(u, V) {
    if (!(s >> u & 1))
      res = min(res, rec(s | (1 << u), u, goal, dist, dp) + dist[v][u]);
  }
  return dp[s][v] = res;
}

template <typename T>
T TravelingSalesman(vector<vector<T>>& dist, int start, int goal) {
  int V = dist.size(), S = (1 << V);
  vector<vector<int>> dp(S, vector<int>(V, -1));
  int IS = (start == goal ? 0 : (1 << start));
  return rec(IS, start, goal, dist, dp);
}

signed main() {
  int V, E;
  cin >> V >> E;

  vector<vector<int>> dist(V, vector<int>(V, INF));

  rep(i, V) {
    dist[i][i] = 0;
  }
  vector<int> s(E), t(E), d(E);
  rep(i, E) {
    cin >> s[i] >> t[i] >> d[i];
    dist[s[i]][t[i]] = d[i];
  }

  /*
  vector<vector<int>> table(V, vector<int>(V));
  rep(s, V) {
    rep(g, V) {
      int temp = TravelingSalesman(dist, s, g);
      if (temp == INF)
        temp = -1;
      table[s][g] = temp;
    }
  }
  cout << table << endl;
  return 0;
  */

  int ans = INF;

  rep(i, V) {
    chmin(ans, TravelingSalesman(dist, i, i));
  }

  if (ans == INF)
    ans = -1;
  cout << ans << endl;
}