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
  int H, W;
  cin >> H >> W;
  vector<vector<char>> S(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> S[i][j];
    }
  }

  vector<vector<char>> ans(H, vector<char>(W, '#'));
  rep(i, H) {
    rep(j, W) {
      if (S[i][j] == '.') {
        repp(ii, -1, 1) {
          repp(jj, -1, 1) {
            if (0 <= i + ii && i + ii < H && 0 <= j + jj && j + jj < W)
              ans[i + ii][j + jj] = '.';
          }
        }
      }
    }
  }

  vector<vector<char>> rec(H, vector<char>(W, '.'));
  rep(i, H) {
    rep(j, W) {
      if (ans[i][j] == '#') {
        repp(ii, -1, 1) {
          repp(jj, -1, 1) {
            if (0 <= i + ii && i + ii < H && 0 <= j + jj && j + jj < W)
              rec[i + ii][j + jj] = '#';
          }
        }
      }
    }
  }

  rep(i, H) {
    rep(j, W) {
      if (S[i][j] != rec[i][j]) {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }

  cout << "possible" << endl;
  rep(i, sz(ans)) {
    rep(j, sz(ans[0])) {
      cout << ans[i][j];

      cout << (j == sz(ans[0]) - 1 ? "\n" : "");
    }
  }
}