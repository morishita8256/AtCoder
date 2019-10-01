#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e+9;

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

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  int N, K;
  cin >> N >> K;
  ll V[N];
  for (int i = 0; i < N; i++)
  {
    cin >> V[i];
  }

  int LR = min(N, K);
  ll ans = 0;
  for (int l = 0; l <= LR; l++)
  {
    for (int r = 0; r <= LR - l; r++)
    {
      vector<ll> val(0);
      for (int i = 0; i < l; i++)
      {
        val.push_back(V[i]);
      }
      for (int i = 0; i < r; i++)
      {
        val.push_back(V[N - 1 - i]);
      }

      sort(val.begin(), val.end());
      for (int i = 0; i < K - l - r; i++)
      {
        if (val.size() > 0 && val[0] < 0)
          val.erase(val.begin());
        else
          break;
      }

      ll sum = 0;
      for (int i = 0; i < val.size(); i++)
      {
        sum += val[i];
      }

      chmax(ans, sum);
    }
  }
  cout << ans << endl;
}