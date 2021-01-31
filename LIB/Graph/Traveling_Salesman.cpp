#pragma region head
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
#pragma endregion

/*
  巡回セールスマン問題。O(N*2^N)。N<=20くらいが限度。
  グローバル宣言されたdistに隣接行列を埋め込んだ状態で
  TravelingSalesman(dist, start, goal);

  startから全ての頂点を1度ずつ通ってgoalまで行くときの最短距離を返す。start=goalの場合はサイクルになる。

  start!=goalの場合は初期状態でstartを訪問済みにするひつようがある。これは変数ISで表している。
*/

using T = int;
vector<vector<T>> dist, dp;

T rec(int s, int v, int goal) {
  int V = dist.size(), S = dp.size();
  if (dp[s][v] >= 0)
    return dp[s][v];
  if (s == S - 1 && v == goal)
    return dp[s][v] = 0;

  int res = INF;
  rep(u, V) {
    if (!(s >> u & 1))
      res = min(res, rec(s | (1 << u), u, goal) + dist[v][u]);
  }
  return dp[s][v] = res;
}

T TravelingSalesman(vector<vector<T>>& dist, int start, int goal) {
  int V = dist.size(), S = (1 << V);
  dp = vector<vector<T>>(S, vector<int>(V, -1));
  int IS = (start == goal ? 0 : (1 << start));
  return rec(IS, start, goal);
}

signed main() {
  int V, E;
  cin >> V >> E;

  dist = vector<vector<int>>(V, vector<int>(V, INF));

  rep(i, V) {
    dist[i][i] = 0;
  }
  vector<int> s(E), t(E), d(E);
  rep(i, E) {
    cin >> s[i] >> t[i] >> d[i];
    dist[s[i]][t[i]] = d[i];
  }

  int ans = INF;

  rep(i, V) {
    chmin(ans, TravelingSalesman(dist, i, i));
  }

  if (ans == INF)
    ans = -1;
  cout << ans << endl;
}