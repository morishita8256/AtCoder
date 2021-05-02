#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e+9 + 7;

ll modpow(ll a, ll n, ll mod)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

long long modinv(long long a, long long mod)
{
  return modpow(a, mod - 2, mod);
}

int main()
{
  int N, K;
  cin >> N >> K;

  for (int i = 1; i <= K; i++)
  {
    ll ans;
    if (i > N - K + 1)
      ans = 0;
    else
    {
      ans = 1;
      for (int j = 0; j < i; j++)
      {
        ans *= N - K + 1 - j;
        ans %= mod;
        ans *= modinv(j + 1, mod);
        ans %= mod;
      }
      if (i >= 2)
      {
        for (int j = 0; j < i - 1; j++)
        {
          ans *= K - 1 - j;
          ans %= mod;
          ans *= modinv(j + 1, mod);
          ans %= mod;
        }
      }
    }
    cout << ans << endl;
  }
}