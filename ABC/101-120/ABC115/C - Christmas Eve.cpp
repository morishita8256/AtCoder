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
  int N, K;
  cin >> N >> K;

  vector<ll> h(N);
  rep(i, N) cin >> h[i];
  sort(all(h));

  vector<ll> diff(N - 1);
  rep(i, N - 1) { diff[i] = h[i + 1] - h[i]; }

  int l = 0, r = 0;

  ll ans = LINF;
  ll temp = 0;

  rep(i, N - K + 1) {
    int nl = i;
    int nr = i + K - 1;

    while (l < nl) {
      temp -= diff[l];
      l++;
    }
    while (r < nr) {
      temp += diff[r];
      r++;
    }
    chmin(ans, temp);
  }
  cout << ans << endl;
}