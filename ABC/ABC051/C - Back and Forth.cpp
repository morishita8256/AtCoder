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
  int sx, sy;
  cin >> sx >> sy;
  int tx, ty;
  cin >> tx >> ty;

  int X = tx - sx;
  int Y = ty - sy;

  rep(i, Y) {
    cout << 'U';
  }
  rep(i, X) {
    cout << 'R';
  }
  rep(i, Y) {
    cout << 'D';
  }
  rep(i, X) {
    cout << 'L';
  }

  cout << 'L';
  rep(i, Y + 1) {
    cout << 'U';
  }
  rep(i, X + 1) {
    cout << 'R';
  }
  cout << 'D';
  cout << 'R';
  rep(i, Y + 1) {
    cout << 'D';
  }
  rep(i, X + 1) {
    cout << 'L';
  }
  cout << 'U';
  cout << endl;
}