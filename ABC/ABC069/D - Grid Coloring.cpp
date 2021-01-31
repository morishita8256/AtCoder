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
  int H, W;
  cin >> H >> W;
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  vector<vector<int>> c(H, vector<int>(W));
  int color = 0;
  int i = 0, j = 0;
  rep(x, H * W) {
    c[i][j] = color + 1;
    a[color]--;
    if (a[color] == 0)
      color++;

    if (i % 2 == 0) {
      if (j != W - 1)
        j++;
      else
        i++;
    } else {
      if (j != 0)
        j--;
      else
        i++;
    }
  }

  rep(i, H) {
    rep(j, W) {
      cout << c[i][j] << ' ';
    }
    cout << endl;
  }
}