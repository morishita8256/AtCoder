#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> W(N);
  for (int i = 0; i < N; i++)
  {
    cin >> W.at(i);
  }

  int S1, S2;
  int diff = 100;
  for (int T = 0; T < N; T++)
  {
    S1 = S2 = 0;
    for (int i = 0; i <= T; i++)
    {
      S1 += W.at(i);
    }
    for (int i = T + 1; i < N; i++)
    {
      S2 += W.at(i);
    }
    diff = min(abs(S1 - S2), diff);
  }
  cout << diff << endl;
}