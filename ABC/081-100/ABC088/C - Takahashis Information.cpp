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
  vector<vector<int>> c(3, vector<int>(3));
  rep(i, 3) {
    rep(j, 3) { cin >> c[i][j]; }
  }

  vector<vector<int>> diff(2, vector<int>(3));
  rep(i, 2) {
    rep(j, 3) { diff[i][j] = c[i + 1][j] - c[i][j]; }
  }

  int yes = true;
  rep(i, 2) {
    rep(j, 2) {
      if (diff[i][j] != diff[i][j + 1]) yes = false;
    }
  }
  if (yes)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}