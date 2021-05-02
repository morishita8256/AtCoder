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

// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// a^{-1} mod を計算する
ll modinv(ll a, ll mod) { return modpow(a, mod - 2, mod); }

int main() {
  string S;
  cin >> S;
  reverse(all(S));

  ll dp[S.size() + 1][13];
  rep(i, S.size() + 1) {
    rep(j, 13) { dp[i][j] = 0; }
  }

  if (S[0] == '?') {
    rep(i, 10) { dp[1][i]++; }
  } else {
    dp[1][S[0] - '0']++;
  }

  repp(i, 2, S.size()) {
    if (S[i - 1] == '?') {
      rep(k, 10) {
        int res = k;
        res *= modpow(10, i - 1, 13);
        res %= 13;
        rep(j, 13) {
          dp[i][(j + res) % 13] += dp[i - 1][j];
          dp[i][(j + res) % 13] %= MOD;
        }
      }
    } else {
      int res = S[i - 1] - '0';
      res *= modpow(10, i - 1, 13);
      res %= 13;
      rep(j, 13) {
        dp[i][(j + res) % 13] += dp[i - 1][j];
        dp[i][(j + res) % 13] %= MOD;
      }
    }
  }
  cout << dp[S.size()][5] << endl;
}