#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e+6

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(3 * N);
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    graph.at(u).push_back(N + v);
    graph.at(N + u).push_back(2 * N + v);
    graph.at(2 * N + u).push_back(v);
  }
  int S, T;
  cin >> S >> T;
  S--;
  T--;

  int min_cnt[3 * N];
  for (int i = 0; i < 3 * N; i++)
  {
    min_cnt[i] = INF;
  }

  queue<int> que;
  que.push(S);
  min_cnt[S] = 0;

  while (que.size())
  {
    int now = que.front();
    que.pop();

    if (now == T)
      break;

    for (auto next : graph.at(now))
    {
      if (min_cnt[next] != INF)
        continue;
      que.push(next);
      min_cnt[next] = min_cnt[now] + 1;
    }
  }

  cout << (min_cnt[T] != INF ? min_cnt[T] / 3 : -1) << endl;
}