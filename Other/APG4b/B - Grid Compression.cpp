#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;

  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> grid.at(i).at(j);
    }
  }

  for (int i = 0; i < H; i++)
  {
    bool H_erase;
    bool W_erase;
    for (int j = 0; j < W; j++)
    {
      H_erase = true;
      W_erase = true;
      for (int ii = 0; ii < H; ii++)
      {
        if (grid.at(ii).at(j) == '#')
        {
          H_erase = false;
          break;
        }
      }
      for (int jj = 0; jj < W; jj++)
      {
        if (grid.at(i).at(jj) == '#')
        {
          W_erase = false;
          break;
        }
      }
      if (!H_erase && !W_erase)
        cout << grid.at(i).at(j);
    }
    if (!W_erase)
      cout << endl;
  }
}
