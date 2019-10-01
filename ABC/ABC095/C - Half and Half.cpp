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
  int A, B, C;
  cin >> A >> B >> C;
  int X, Y;
  cin >> X >> Y;

  ll ans = LINF;
  for (int ab = 0; ab / 2 <= max(X, Y); ab += 2) {
    int a = max(X - ab / 2, 0);
    int b = max(Y - ab / 2, 0);

    int price = a * A + b * B + ab * C;
    chmin(ans, (ll)price);
  }
  cout << ans << endl;
}