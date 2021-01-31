#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

ll dfs(int K, vector<vector<int>> &graph, int from, int now)
{
  int usable_color;
  if (from == -1)
  {
    usable_color = K - 1;
  }
  else
  {
    usable_color = K - 2;
  }

  ll comb = 1;
  for (auto next : graph.at(now))
  {
    if (next == from)
      continue;
    comb *= usable_color--;
    comb %= mod;
  }
  for (auto next : graph.at(now))
  {
    if (next == from)
      continue;
    comb *= dfs(K, graph, now, next);
    comb %= mod;
  }
  return comb;
}

int main()
{
  int N, K;
  cin >> N >> K;
  vector<vector<int>> graph(N);
  for (int i = 1; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }
  ll ans;
  ans = K * dfs(K, graph, -1, 0) % mod;
  cout << ans << endl;
}