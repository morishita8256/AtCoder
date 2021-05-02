#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  int N;
  cin >> N;
  ll A[N];
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  ll all = 0;
  ll ans[N];
  for (int i = 0; i < N; i++)
  {
    all += A[i];
  }

  ans[0] = all;
  for (int i = 1; i < N; i += 2)
  {
    ans[0] -= 2 * A[i];
  }
  for (int i = 1; i < N; i++)
  {
    ans[i] = 2 * A[i - 1] - ans[i - 1];
  }

  for (int i = 0; i < N; i++)
  {
    cout << ans[i];
    if (i == N - 1)
      cout << endl;
    else
      cout << ' ';
  }
}