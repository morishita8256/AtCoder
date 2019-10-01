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
  vector<vector<char>> S(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) { cin >> S[i][j]; }
  }

  auto A = S;

  rep(i, H) {
    rep(j, W) {
      if (A[i][j] == '#')
        continue;

      int cnt = 0;
      repp(ii, max(0, i - 1), min(H - 1, i + 1)) {
        repp(jj, max(0, j - 1), min(W - 1, j + 1)) {
          if (S[ii][jj] == '#')
            cnt++;
        }
      }
      A[i][j] = cnt + '0';
    }
  }

  rep(i, H) {
    rep(j, W) { cout << A[i][j]; }
    cout << endl;
  }
}