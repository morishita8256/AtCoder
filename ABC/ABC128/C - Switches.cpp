#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N, M;
  cin >> N >> M;
  int k[M];
  int s[M][N];

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      s[i][j] = 0;
    }
  }

  for (int i = 0; i < M; i++)
  {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++)
    {
      int S;
      cin >> S;
      s[i][S - 1] = 1;
    }
  }
  int p[M];
  for (int i = 0; i < M; i++)
  {
    cin >> p[i];
  }

  int ans = 0;

  int sw[N];
  int sum;
  for (int i = 0; i < (1 << N); i++)
  {
    for (int n = 0; n < N; n++)
    {
      sw[n] = (i >> n) & 1;
    }

    bool good = true;
    for (int m = 0; m < M; m++)
    {
      sum = 0;
      for (int n = 0; n < N; n++)
      {
        sum += s[m][n] * sw[n];
      }
      if (sum % 2 != p[m])
      {
        good = false;
        break;
      }
    }
    if (good)
      ans++;
  }
  cout << ans << endl;
}