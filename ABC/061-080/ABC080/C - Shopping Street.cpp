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
  int N;
  cin >> N;
  vector<vector<int>> F(N, vector<int>(10));
  rep(i, N) {
    rep(j, 10) { cin >> F[i][j]; }
  }
  vector<vector<int>> P(N, vector<int>(11));
  rep(i, N) {
    rep(j, 11) { cin >> P[i][j]; }
  }

  int ans = -INF;
  repp(i, 1, (1 << 10) - 1) {
    vector<int> f(10);
    rep(j, 10) { f[j] = i >> j & 1; }

    int bene = 0;
    rep(j, N) {
      int accord = 0;
      rep(k, 10) { accord += f[k] * F[j][k]; }
      bene += P[j][accord];
    }
    chmax(ans, bene);
  }
  cout << ans << endl;
}