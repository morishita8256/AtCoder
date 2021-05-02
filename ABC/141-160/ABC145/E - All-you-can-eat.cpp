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
  ll N, T;
  cin >> N >> T;
  vector<ll> A(N), B(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
  }

  T--;
  vector<vector<ll>> dp1(N + 1, vector<ll>(T + 1));
  rep(n, N) {
    rep(j, T + 1) {
      // not eat
      chmax(dp1[n + 1][j], dp1[n][j]);

      // eat
      if (j + A[n] > T)
        continue;
      chmax(dp1[n + 1][j + A[n]], dp1[n][j] + B[n]);
    }
  }

  reverse(all(A));
  reverse(all(B));
  vector<vector<ll>> dp2(N + 1, vector<ll>(T + 1));
  rep(n, N) {
    rep(j, T + 1) {
      // not eat
      chmax(dp2[n + 1][j], dp2[n][j]);

      // eat
      if (j + A[n] > T)
        continue;
      chmax(dp2[n + 1][j + A[n]], dp2[n][j] + B[n]);
    }
  }

  reverse(all(A));
  reverse(all(B));


  ll ans = 0;
  rep(i, N) {
    ll temp = 0;
    rep(j, T + 1) {
      ll tempp = 0;
      if (i > 0)
        tempp += dp1[i][j];
      if (i < N - 1)
        tempp += dp2[N - i - 1][T - j];
      chmax(temp, tempp);
    }
    temp += B[i];
    chmax(ans, temp);
  }
  cout << ans << endl;
}