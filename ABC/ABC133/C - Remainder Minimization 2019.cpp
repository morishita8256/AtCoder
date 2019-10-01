#include <bits/stdc++.h>
using namespace std;
#define int long long

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

signed main()
{
  int L, R;
  cin >> L >> R;
  int l, r;
  if (L / 2019 == R / 2019)
  {
    l = L;
    r = R;
  }
  else if (R < L + 2019)
  {
    l = R;
    r = L;
  }
  else
  {
    l = 0;
    r = 2018;
  }

  int ans = 1E+8;
  for (int i = l; i <= r - 1; i++)
  {
    for (int j = i + 1; j <= r; j++)
    {
      chmin(ans, ((i % 2019) * (j % 2019)) % 2019);
    }
  }
  cout << ans << endl;
}