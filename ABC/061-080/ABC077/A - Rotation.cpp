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
  vector<vector<char>> C(2, vector<char>(3));
  rep(i, 2) {
    rep(j, 3) { cin >> C[i][j]; }
  }

  bool yes = true;
  rep(i, 3) {
    if (C[0][i] != C[1][2 - i])
      yes = false;
  }
  if (yes)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}