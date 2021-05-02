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
  vector<int> t(N + 1), x(N + 1), y(N + 1);
  t[0] = 0;
  x[0] = 0;
  y[0] = 0;
  repp (i, 1, N)
    cin >> t[i] >> x[i] >> y[i];

  rep (i, N) {
    int dt = t[i + 1] - t[i];
    int dx = abs(x[i + 1] - x[i]);
    int dy = abs(y[i + 1] - y[i]);
    int dr = dx + dy;
    if (dt >= dr && (dt - dr) % 2 == 0) {
      continue;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}