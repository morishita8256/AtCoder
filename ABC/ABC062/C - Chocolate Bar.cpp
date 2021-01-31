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
  ll H, W;
  cin >> H >> W;

  if (H % 3 == 0 || W % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = min(H, W);
  repp(a, H / 3, H / 3 + 1) {
    repp(b, W / 2, W / 2 + 1) {
      ll A = a * W;
      ll B = (H - a) * b;
      ll C = (H - a) * (W - b);

      ll S = max({A, B, C}) - min({A, B, C});

      chmin(ans, S);
    }
  }
  swap(H, W);
  repp(a, H / 3, H / 3 + 1) {
    repp(b, W / 2, W / 2 + 1) {
      ll A = a * W;
      ll B = (H - a) * b;
      ll C = (H - a) * (W - b);

      ll S = max({A, B, C}) - min({A, B, C});

      chmin(ans, S);
    }
  }

  cout << ans << endl;
}