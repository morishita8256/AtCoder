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
  int x1, y1;
  cin >> x1 >> y1;
  int x2, y2;
  cin >> x2 >> y2;

  int x3, y3, x4, y4;
  x3 = x2 - (y2 - y1);
  y3 = y2 - (x1 - x2);
  x4 = x1 - (y2 - y1);
  y4 = y1 - (x1 - x2);

  cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;
}