#include <bits/stdc++.h>
using namespace std;

const int MAX_W = 1e+5;

int main()
{
  int N, W;
  cin >> N >> W;
  int w[N + 1], v[N + 1];
  for (int i = 1; i <= N; i++)
  {
    cin >> w[i] >> v[i];
  }

  long long int dp[N + 1][W + 1];
  for (int i = 1; i <= N; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      dp[i][j] = -1;
    }
  }

  /* i番目までの品物でjの重さを作ったときの最大価値がdp[i][j] */

  dp[1][0] = 0;
  dp[1][w[1]] = v[1];

  for (int i = 1; i <= N - 1; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      if (dp[i][j] != -1)
      {
        dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]); // 上書きに注意
        if (j + w[i + 1] <= W)
        {
          dp[i + 1][j + w[i + 1]] =
              max(dp[i][j] + v[i + 1], dp[i + 1][j + w[i + 1]]);
        }
      }
    }
  }

  long long int max_v = 0;
  for (int j = 0; j <= W; j++)
  {
    max_v = max(max_v, dp[N][j]);
  }
  cout << max_v << endl;
  // for (int i = 1; i <= N; i++)
  // {
  //   for (int j = 0; j <= W; j++)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}