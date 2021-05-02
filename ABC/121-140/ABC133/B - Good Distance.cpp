#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, D;
  cin >> N >> D;
  int X[N][D];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < D; j++)
    {
      cin >> X[i][j];
    }
  }

  int ans = 0;
  double norm2;
  double norm;
  double eps = 1E-7;
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      norm2 = 0;
      for (int d = 0; d < D; d++)
      {
        norm2 += pow(X[i][d] - X[j][d], 2);
      };
      if (ceil(sqrt(norm2)) == floor(sqrt(norm2)))
        ans++;
    }
  }
  cout << ans << endl;
}