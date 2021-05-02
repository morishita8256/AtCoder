#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

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
  int N;
  cin >> N;
  vector<P> v(N);

  for (int i = 0; i < N; i++)
  {
    cin >> v[i].second >> v[i].first; // (B,A)
  }

  sort(v.begin(), v.end());
  // greater<ll>()は無理っぽい？

  ll now = 1e10;
  for (int i = N - 1; i >= 0; i--)
  {
    chmin(now, v[i].first);
    now -= v[i].second;
  }
  cout << (now >= 0 ? "Yes" : "No") << endl;
}