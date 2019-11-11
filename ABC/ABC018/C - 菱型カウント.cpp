#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define sz(x) ((ll)(x).size())
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
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<char>> s(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> s[i][j];
    }
  }

  int ans = 0;
  repp(y, K - 1, H - K) {
    repp(x, K - 1, W - K) {
      bool ok = true;
      repp(i, -K + 1, K - 1) {
        repp(j, -K + 1 + abs(i), K - 1 - abs(i)) {
          if (s[y + i][x + j] == 'x') {
            ok = false;
          }
        }
      }
      if (ok)
        ans++;
    }
  }
  cout << ans << endl;
}