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
  int A, B;
  cin >> A >> B;

  vector<vector<char>> G(100, vector<char>(100));
  repp(i, 0, 49) {
    rep(j, 100) {
      G[i][j] = '#';
    }
  }
  repp(i, 50, 99) {
    rep(j, 100) {
      G[i][j] = '.';
    }
  }

  A--;
  B--;
  int ai = A / 50;
  int aj = A % 50;
  for (int i = 0; i < ai * 2; i += 2) {
    for (int j = 0; j < 50 * 2; j += 2) {
      G[i][j] = '.';
    }
  }
  for (int j = 0; j < aj * 2; j += 2) {
    G[ai * 2][j] = '.';
  }

  A--;
  int bi = B / 50;
  int bj = B % 50;
  for (int i = 0; i < bi * 2; i += 2) {
    for (int j = 0; j < 50 * 2; j += 2) {
      G[99 - i][99 - j] = '#';
    }
  }
  for (int j = 0; j < bj * 2; j += 2) {
    G[99 - bi * 2][99 - j] = '#';
  }

  cout << 100 << ' ' << 100 << endl;
  rep(i, 100) {
    rep(j, 100) {
      cout << G[i][j];
    }
    cout << endl;
  }
}