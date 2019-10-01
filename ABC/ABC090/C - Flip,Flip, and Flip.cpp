#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ll N, M;
  cin >> N >> M;

  ll ans;
  if (N == 1) {
    if (M == 1)
      ans = 1;
    else if (M == 2)
      ans = 0;
    else
      ans = M - 2;
  } else if (N == 2) {
    ans = 0;
  } else {
    if (M == 1)
      ans = N - 2;
    else if (M == 2)
      ans = 0;
    else
      ans = (N - 2) * (M - 2);
  }
  cout << ans << endl;
}