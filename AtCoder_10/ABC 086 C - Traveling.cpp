#include <bits/stdc++.h>
using namespace std;

bool is_possible(int dt, int dx, int dy)
{
  int dr = abs(dx) + abs(dy);
  while (dt > dr)
    dt -= 2;
  if (dt == dr)
    return true;
  else
    return false;
}

int main()
{
  int N;
  cin >> N;

  vector<int> t(N + 1);
  vector<int> x(N + 1);
  vector<int> y(N + 1);

  t.at(0) = 0;
  x.at(0) = 0;
  y.at(0) = 0;

  for (int i = 1; i <= N; i++)
  {
    cin >> t.at(i) >> x.at(i) >> y.at(i);
  }

  for (int i = 0; i < N; i++)
  {
    if (!is_possible(t.at(i + 1) - t.at(i), x.at(i + 1) - x.at(i), y.at(i + 1) - y.at(i)))
    {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}