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

  while (true)
  {
    int N;
    ll M;
    cin >> N >> M;
    if (N + M == 0)
      break;
    vector<ll> P(N + 1);
    P.at(0) = 0;
    reps(i, N) cin >> P.at(i);
    int NN = pow(N + 1, 2);

    vector<ll>
        PP(NN);
    rep(i, N + 1)
        rep(j, N + 1)
            PP.at(i * (N + 1) + j) = P.at(i) + P.at(j);

    sort(all(PP));

    ll maxp = 0;
    rep(i, NN)
    {
      ll aim = M - PP.at(i);
      if (aim < 0) /* ここを忘れない */
        continue;
      chmax(maxp, PP.at(i) + *(upper_bound(all(PP), aim) - 1));
    }
    cout << maxp << endl;
  }
}