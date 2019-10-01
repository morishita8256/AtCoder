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
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;
  int N = s.size();

  vector<int> o;
  s.pb('T');
  int cnt = 0;
  rep(i, s.size()) {
    if (s[i] == 'T') {
      o.pb(cnt);
      cnt = 0;
    } else {
      cnt++;
    }
  }

  vector<int> xx;
  vector<int> yy;
  x -= o[0];
  repp(i, 1, o.size() - 1) {
    if (i % 2 == 0) {
      xx.pb(o[i]);
    } else {
      yy.pb(o[i]);
    }
  }

  N *= 2;
  int X = xx.size();
  vector<vector<bool>> xdp(X + 1, vector<bool>(2 * N + 1, false));
  xdp[0][N] = true;
  rep(i, X) {
    rep(j, 2 * N + 1) {
      int nj = j + xx[i];
      if (nj < 2 * N * 1)
        xdp[i + 1][nj] = (xdp[i][j] || xdp[i + 1][nj]);

      nj = j - xx[i];
      if (nj >= 0)
        xdp[i + 1][nj] = (xdp[i][j] || xdp[i + 1][nj]);
    }
  }
  bool XX = xdp[X][N + x];

  int Y = yy.size();
  vector<vector<bool>> ydp(Y + 1, vector<bool>(2 * N + 1, false));
  ydp[0][N] = true;
  rep(i, Y) {
    rep(j, 2 * N + 1) {
      int nj = j + yy[i];
      if (nj < 2 * N * 1)
        ydp[i + 1][nj] = (ydp[i][j] || ydp[i + 1][nj]);

      nj = j - yy[i];
      if (nj >= 0)
        ydp[i + 1][nj] = (ydp[i][j] || ydp[i + 1][nj]);
    }
  }
  bool YY = ydp[Y][N + y];

  if (XX && YY)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}