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
  string S;
  cin >> S;

  vector<vector<bool>> L(N, vector<bool>(10, false));
  repp(i, 1, N - 1) {
    rep(j, 10) {
      if (L[i - 1][j])
        L[i][j] = true;
      L[i][S[i - 1] - '0'] = true;
    }
  }

  vector<vector<bool>> R(N, vector<bool>(10, false));
  repr(i, N - 2, 0) {
    rep(j, 10) {
      if (R[i + 1][j])
        R[i][j] = true;
      R[i][S[i + 1] - '0'] = true;
    }
  }


  vector<vector<vector<bool>>> cnt(
      10, vector<vector<bool>>(10, vector<bool>(10, false)));

  rep(i, N) {
    int c = S[i] - '0';
    rep(j, 10) {
      rep(k, 10) {
        if (L[i][j] && R[i][k])
          cnt[j][c][k] = true;
      }
    }
  }

  int ans = 0;
  rep(i, 10) {
    rep(j, 10) {
      rep(k, 10) {
        if (cnt[i][j][k])
          ans++;
      }
    }
  }
  cout << ans << endl;
}