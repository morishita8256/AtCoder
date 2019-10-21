#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int a[N + 1], b[N + 1], c[N + 1];

  for (int i = 1; i <= N; i++)
  {
    cin >> a[i] >> b[i] >> c[i];
  }

  /* i日目にaをしたときの累積最大幸福度がh[i][0] */

  int h[N + 1][3];
  h[1][0] = a[1];
  h[1][1] = b[1];
  h[1][2] = c[1];
  for (int i = 2; i <= N; i++)
  {
    h[i][0] = a[i] + max(h[i - 1][1], h[i - 1][2]);
    h[i][1] = b[i] + max(h[i - 1][2], h[i - 1][0]);
    h[i][2] = c[i] + max(h[i - 1][0], h[i - 1][1]);
  }

  cout << max(h[N][0], max(h[N][1], h[N][2])) << endl;
}