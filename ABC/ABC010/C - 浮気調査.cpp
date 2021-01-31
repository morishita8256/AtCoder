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

double dist(double x, double y, double xx, double yy) {
  return sqrt(pow(x - xx, 2) + pow(y - yy, 2));
}

int main() {
  double sx, sy;
  cin >> sx >> sy;
  double gx, gy;
  cin >> gx >> gy;
  double T, V;
  cin >> T >> V;
  int n;
  cin >> n;
  vector<double> x(n), y(n);
  rep(i, n) {
    cin >> x[i] >> y[i];
  }

  rep(i, n) {
    double distance = dist(sx, sy, x[i], y[i]) + dist(gx, gy, x[i], y[i]);
    double time = distance / V;
    if (time <= T) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}