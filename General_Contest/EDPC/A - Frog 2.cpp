#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;

  vector<int> h(N + 1);
  for (int i = 1; i <= N; i++)
  {
    cin >> h.at(i);
  }

  vector<long long int> min_cost(N + 1);
  for (int i = 0; i < N + 1; i++)
  {
    min_cost.at(i) = 1e+12;
  }
  min_cost.at(1) = 0;

  for (int i = 1; i <= N - 1; i++)
  {
    for (int j = 1; j <= min(K, N - i); j++)
    {
      min_cost.at(i + j) =
          min(min_cost.at(i + j),
              min_cost.at(i) + abs(h.at(i + j) - h.at(i)));
    }
  }
  cout << min_cost.at(N) << endl;
}