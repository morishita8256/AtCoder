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
const int MOD = 1000000007;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  vector<int> x(N), y(N), a(N);
  rep(i, N) cin >> x[i] >> y[i] >> a[i];
  int xmn = 0, xmx = W, ymn = 0, ymx = H;
  rep(i, N) {
    switch (a[i]) {
      case 1:
        chmax(xmn, x[i]);
        break;
      case 2:
        chmin(xmx, x[i]);
        break;
      case 3:
        chmax(ymn, y[i]);
        break;
      case 4:
        chmin(ymx, y[i]);
        break;
    }
  }
  int ans = max(0, xmx - xmn) * max(0, ymx - ymn);
  cout << ans << endl;
}