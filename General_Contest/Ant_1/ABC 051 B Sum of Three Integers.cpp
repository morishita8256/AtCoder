#include <bits/stdc++.h>
using namespace std;

int main()
{
  int K, S;
  cin >> K >> S;

  int cnt = 0;
  for (int X = 0; X < K + 1; X++)
  {
    for (int Y = 0; Y < K + 1; Y++)
    {
      if (0 <= S - X - Y && S - X - Y <= K)
        cnt++;
    }
  }
  cout << cnt << endl;
}