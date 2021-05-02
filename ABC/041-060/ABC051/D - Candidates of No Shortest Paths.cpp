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
#define sz(x) ((int)(x).size())
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
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M), c(M);
  vector<vector<int>> d(N, vector<int>(N, INF));
  rep(i, M) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    d[a[i]][b[i]] = c[i];
    d[b[i]][a[i]] = c[i];
  }
  rep(i, N) {
    d[i][i] = 0;
  }

  auto d_init = d;
  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        chmin(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int ans = 0;
  rep(i, N) {
    rep(j, N) {
      if (d[i][j] != d_init[i][j] && d_init[i][j] != INF)
        ans++;
    }
  }
  ans /= 2;
  cout << ans << endl;
}