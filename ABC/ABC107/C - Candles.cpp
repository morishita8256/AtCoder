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
  vector<int> x(N);
  int ind_of_lower_0;
  rep(i, N) { cin >> x[i]; }

  int ans = INF;
  rep(i, N - K + 1) {
    int l = i;
    int r = i + K - 1;
    if (x[r] <= 0)
      chmin(ans, abs(x[l]));
    else if (x[l] >= 0)
      chmin(ans, x[r]);
    else {
      int l_abs = abs(x[l]);
      int r_abs = x[r];
      chmin(ans, l_abs + r_abs + min(l_abs, r_abs));
    }
  }
  cout << ans << endl;
}