#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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
  int x, y;
  string W;
  cin >> x >> y >> W;
  x += 2;
  y += 2;

  vector<vector<char>> c(15, vector<char>(15));
  rep(i, 9) {
    rep(j, 9) {
      cin >> c[i + 3][j + 3];
    }
  }
  repp(i, 0, 2) {
    repp(j, 3, 11) {
      c[i][j] = c[6 - i][j];
    }
  }
  repp(i, 12, 14) {
    repp(j, 3, 11) {
      c[i][j] = c[22 - i][j];
    }
  }
  rep(i, 15) {
    repp(j, 0, 2) {
      c[i][j] = c[i][6 - j];
    }
  }
  rep(i, 15) {
    repp(j, 12, 14) {
      c[i][j] = c[i][22 - j];
    }
  }

  int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
  int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
  map<string, int> m;
  m["R"] = 0;
  m["L"] = 1;
  m["U"] = 2;
  m["D"] = 3;
  m["RU"] = 4;
  m["RD"] = 5;
  m["LU"] = 6;
  m["LD"] = 7;

  string ans = "hoge";
  rep(i, 4) {
    ans[i] = c[y][x];
    y += dy[m[W]];
    x += dx[m[W]];
  }
  cout << ans << endl;
}
