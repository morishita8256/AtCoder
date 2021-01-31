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
  int H, W;
  cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> a[i][j];
    }
  }

  int N = 0;
  vector<vector<int>> yxyx;

  rep(i, H) {
    rep(j, W - 1) {
      if (a[i][j] % 2) {
        a[i][j]--;
        a[i][j + 1]++;
        N++;
        vector<int> temp = {i + 1, j + 1, i + 1, j + 2};
        yxyx.pb(temp);
      }
    }
  }

  int j = W - 1;
  rep(i, H - 1) {
    if (a[i][j] % 2) {
      a[i][j]--;
      a[i + 1][j]++;
      N++;
      vector<int> temp = {i + 1, j + 1, i + 2, j + 1};
      yxyx.pb(temp);
    }
  }

  cout << N << endl;
  rep(i, yxyx.size()) {
    rep(j, 4) {
      cout << yxyx[i][j];
      if (j != 3)
        cout << ' ';
    }
    cout << endl;
  }
}