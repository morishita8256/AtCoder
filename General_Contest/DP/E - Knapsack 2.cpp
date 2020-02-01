#include <bits/stdc++.h>
using namespace std;
long long int INF = 1e+10;
int Nv = 1e+5;

int main()
{
  int N, W;
  cin >> N >> W;
  int w[N + 1], v[N + 1];
  for (int i = 1; i <= N; i++)
  {
    cin >> w[i] >> v[i];
  }

  /* i番目までの品物で価値jにしたときの最小重みがdp[i][j] */
  long long int dp[N + 1][int(1e+5) + 1];
  for (int i = 0; i < N + 1; i++)
  {
    for (int j = 0; j < Nv + 1; j++)
    {
      dp[i][j] = INF;
    }
  }
  dp[1][0] = 0;
  dp[1][v[1]] = w[1];

  for (int i = 1; i <= N - 1; i++)
  {
    for (int j = 0; j <= Nv; j++)
    {
      if (dp[i][j] != INF)
      {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        if (dp[i][j] + w[i + 1] <= W)
        {
          dp[i + 1][j + v[i + 1]] =
              min(dp[i + 1][j + v[i + 1]],
                  dp[i][j] + w[i + 1]);
        }
      }
    }
  }
  int max_v;
  for (int j = 0; j <= Nv; j++)
  {
    if (dp[N][j] != INF)
      max_v = j;
  }

  cout << max_v << endl;
}