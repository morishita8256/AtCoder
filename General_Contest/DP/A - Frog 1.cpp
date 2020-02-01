#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> h(N + 1);
  for (int i = 1; i <= N; i++)
  {
    cin >> h.at(i);
  }

  vector<int> cost(N + 1);
  cost.at(1) = 0;
  cost.at(2) = abs(h.at(2) - h.at(1));

  for (int i = 3; i <= N; i++)
  {
    cost.at(i) =
        min(cost.at(i - 2) + abs(h.at(i) - h.at(i - 2)),
            cost.at(i - 1) + abs(h.at(i) - h.at(i - 1)));
  }

  cout << cost.at(N) << endl;
}