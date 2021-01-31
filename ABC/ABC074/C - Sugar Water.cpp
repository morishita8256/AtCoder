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
  int A, B;
  cin >> A >> B;
  int C, D;
  cin >> C >> D;
  int E, F;
  cin >> E >> F;

  double conc = -1.0;
  int ans_water;
  int ans_suger;
  repp(a, 0, 30) {
    repp(b, 0, 15) {
      if (a == 0 && b == 0)
        continue;
      int water = 100 * A * a + 100 * B * b;
      if (water > F)
        break;

      int max_suger = min(F - water, water * E / 100);

      repp(c, 0, max_suger) {
        if (c * C > max_suger)
          break;
        int d = (max_suger - C * c) / D;
        int suger = c * C + d * D;

        double conc_temp = (double)suger / (suger + water);
        if (chmax(conc, conc_temp)) {
          ans_water = water;
          ans_suger = suger;
        }
      }
    }
  }
  cout << ans_water + ans_suger << ' ' << ans_suger << endl;
}