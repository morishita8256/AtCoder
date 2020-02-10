#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
template <class T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return 1;
  }
  return 0;
}

signed main()
{
  string s, t;
  cin >> s >> t;
  int ls = s.size();
  int lt = t.size();

  int dp[ls + 1][lt + 1];
  rep(i, ls + 1)
      dp[i][0] = 0;
  rep(j, lt + 1)
      dp[0][j] = 0;

  rep(i, ls)
      rep(j, lt)
  {
    if (s[i] == t[j])
      dp[i + 1][j + 1] = dp[i][j] + 1;
    else
      dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
  }

  string ans = "";
  int i = ls;
  int j = lt;
  while (i > 0 && j > 0)
  {
    if (s[i - 1] == t[j - 1])
    {
      ans += s[i - 1];
      i--;
      j--;
    }
    else if (dp[i][j] == dp[i - 1][j])
    {
      i--;
    }
    else
    {
      j--;
    }
  }
  reverse(all(ans));
  cout << ans << endl;
}