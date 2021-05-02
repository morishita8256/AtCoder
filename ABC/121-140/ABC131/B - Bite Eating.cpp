#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  int N, L;
  cin >> N >> L;

  int sum = 0;
  int min_abs = 1000;
  int min_abs_raw = 1000;

  for (int i = 1; i <= N; i++)
  {
    sum += L + i - 1;
    if (chmin(min_abs, abs(L + i - 1)))
      min_abs_raw = L + i - 1;
  }
  sum -= min_abs_raw;
  cout << sum << endl;
}