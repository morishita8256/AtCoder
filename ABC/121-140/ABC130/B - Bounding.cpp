#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N, X;
  cin >> N >> X;
  int L[N];
  for (int i = 0; i < N; i++)
  {
    cin >> L[i];
  }

  int cnt = 1;
  int dist = 0;
  for (int i = 0; i < N; i++)
  {
    dist += L[i];
    if (dist <= X)
      cnt++;
    else
      break;
  }
  cout << cnt << endl;
}