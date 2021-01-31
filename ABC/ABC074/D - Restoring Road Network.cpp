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
  if (a >= b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a <= b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N));
  rep(i, N) {
    rep(j, N) {
      cin >> A[i][j];
    }
  }

  vector<vector<bool>> need(N, vector<bool>(N, true));
  rep(i, N) {
    rep(j, N) {
      rep(k, N) {
        if (k == i || k == j)
          continue;

        if (A[i][j] > A[i][k] + A[k][j]) {
          cout << -1 << endl;
          return 0;
        }

        if (A[i][j] == A[i][k] + A[k][j])
          need[i][j] = false;
      }
    }
  }

  ll ans = 0;
  rep(i, N - 1) {
    repp(j, i + 1, N - 1) {
      if (need[i][j])
        ans += A[i][j];
    }
  }
  cout << ans << endl;
}