#include <bits/stdc++.h>
using namespace std;

void search(vector<vector<char>> map, vector<vector<bool>> &reached, int i, int j)
{
  if (i < 0 || i > 9 || j < 0 || j > 9)
    return;
  if (map.at(i).at(j) == 'x' || reached.at(i).at(j))
    return;
  reached.at(i).at(j) = true;

  search(map, reached, i, j + 1);
  search(map, reached, i, j - 1);
  search(map, reached, i + 1, j);
  search(map, reached, i - 1, j);
}

bool is_single_island(vector<vector<char>> map, int i, int j)
{
  vector<vector<bool>> reached(10, vector<bool>(10, false));
  map.at(i).at(j) = 'o';
  search(map, reached, i, j);
  int cnt_map = 0, cnt_reached = 0;
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (map.at(i).at(j) == 'o')
        cnt_map++;
      if (reached.at(i).at(j) == true)
        cnt_reached++;
    }
  }
  return cnt_map == cnt_reached;
}

int main()
{
  vector<vector<char>> map(10, vector<char>(10));
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      cin >> map.at(i).at(j);
    }
  }

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (is_single_island(map, i, j))
      {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}