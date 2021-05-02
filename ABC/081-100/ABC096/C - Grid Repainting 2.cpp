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
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) { cin >> s[i][j]; }
  }

  rep(i, H) {
    rep(j, W) {
      bool ok = true;
      if (s[i][j] == '#') {
        ok = false;
        if (i - 1 >= 0) {
          if (s[i - 1][j] == '#') ok = true;
        }
        if (i + 1 <= H - 1) {
          if (s[i + 1][j] == '#') ok = true;
        }
        if (j - 1 >= 0) {
          if (s[i][j - 1] == '#') ok = true;
        }
        if (j + 1 <= W - 1) {
          if (s[i][j + 1] == '#') ok = true;
        }
      }

      if (ok == false) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}