#include <bits/stdc++.h>
using namespace std;
long long int mod = 1E+9 + 7;

/* 差がdiffの壊れ床間の移動法 -> フィボナッチ数列の第diff-1項 */
long long int combination(int diff)
{
  if (diff == 1)
    return 0;
  if (diff == 2)
    return 1;
  long long int a, b, c;
  a = 0;
  b = 1;
  for (int i = 1; i < diff - 1; i++)
  {
    c = a + b;
    c %= mod;
    a = b;
    b = c;
  }
  return c;
}

int main()
{
  int N, M;
  cin >> N >> M;

  vector<int> a(M + 2);
  a.at(0) = -1;
  for (int i = 1; i <= M; i++)
  {
    cin >> a.at(i);
  }
  a.at(M + 1) = N + 1;

  long long int ans = 1;
  for (int i = 0; i < M + 1; i++)
  {
    ans = (ans * (combination(a.at(i + 1) - a.at(i)) % mod)) % mod;
  };
  cout << ans << endl;
}