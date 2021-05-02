#include <bits/stdc++.h>
using namespace std;
#define int long long

/* 嘘解法 */
int main()
{
  int H, W;
  cin >> H >> W;
  char S[H][W];
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> S[i][j];
    }
  }

  int maxcnt = 0;
  int temp;

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (S[i][j] == '#')
        continue;
      temp = 1;
      for (int ii = i - 1; ii >= 0; ii--)
      {
        if (S[ii][j] == '#')
          break;
        temp++;
      }
      for (int ii = i + 1; ii <= H - 1; ii++)
      {
        if (S[ii][j] == '#')
          break;
        temp++;
      }
      for (int jj = j - 1; jj >= 0; jj--)
      {
        if (S[i][jj] == '#')
          break;
        temp++;
      }
      for (int jj = j + 1; jj <= W - 1; jj++)
      {
        if (S[i][jj] == '#')
          break;
        temp++;
      }
      maxcnt = max(maxcnt, temp);
      if (maxcnt == W + H - 1)
        break;
    }
  }
  cout << maxcnt << endl;
}