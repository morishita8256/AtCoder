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
  int N;
  cin >> N;
  vector<int> A(N);
  vector<vector<int>> x(N);
  vector<vector<int>> y(N);

  int X, Y;
  rep(i, N) {
    cin >> A[i];
    rep(j, A[i]) {
      cin >> X >> Y;
      X--;
      x[i].pb(X);
      y[i].pb(Y);
    }
  }

  int ans = 0;
  rep(b, bit(N)) {
    vector<int> B(N);
    int cnt = 0;
    rep(i, N) {
      if ((b >> i) & 1) {
        B[i] = 1;
        cnt++;
      } else
        B[i] = 0;
    }

    bool ok = true;
    rep(i, N) {
      if (!B[i])
        continue;
      rep(j, A[i]) {
        int to = x[i][j];
        if (B[to] != y[i][j])
          ok = false;
      }
    }
    if (ok)
      chmax(ans, cnt);
  }
  cout << ans << endl;
}