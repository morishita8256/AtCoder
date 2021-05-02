#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N, K;
  cin >> N >> K;

  if (K > (N - 1) * (N - 2) / 2)
  {
    cout << -1 << endl;
    return 0;
  }

  int C = (N - 1) * (N - 2) / 2 - K;

  cout << N - 1 + C << endl;

  for (int i = 2; i <= N; i++)
  {
    cout << 1 << ' ' << i << endl;
  }

  for (int i = 2; i <= N - 1; i++)
  {
    if (C == 0)
      break;
    for (int j = i + 1; j <= N; j++)
    {
      if (C == 0)
        break;
      cout << i << ' ' << j << endl;
      C--;
    }
  }
}