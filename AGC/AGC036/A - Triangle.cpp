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
  ll S;
  cin >> S;
  ll X1, Y1, X2, Y2, X3, Y3;
  X1 = 0;
  Y1 = 0;
  X2 = ll(1e+9);
  Y2 = 1;
  Y3 = (S + ll(1e+9) - 1) / ll(1e+9);  // キャストしないと浮動小数点誤差でバグる
  X3 = ll(1e+9) * Y3 - S;

  cout << X1 << ' ';
  cout << Y1 << ' ';
  cout << X2 << ' ';
  cout << Y2 << ' ';
  cout << X3 << ' ';
  cout << Y3;
  cout << endl;
}