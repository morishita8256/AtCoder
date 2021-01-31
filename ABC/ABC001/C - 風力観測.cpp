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
const double EPS = 1e-9;

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
  double Deg, Dis;
  cin >> Deg >> Dis;

  vector<double> sub = {0.3,  1.6,  3.4,  5.5,  8.0,  10.8,
                        13.9, 17.2, 20.8, 24.5, 28.5, 32.7};
  Dis /= 60.0;

  int W = 0;
  rep(i, sz(sub)) {
    if (Dis >= sub[i] - 0.05 - EPS)
      W++;
  }

  Deg /= 10.0;
  Deg += 11.25;
  int deg = Deg / 22.5;
  deg %= 16;
  vector<string> dir = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
                        "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
  string Dir = dir[deg];
  if (W == 0)
    Dir = "C";

  cout << Dir << ' ' << W << endl;
}