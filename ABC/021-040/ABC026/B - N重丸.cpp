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

double circle(double r) {
  return M_PI * r * r;
}

int main() {
  int N;
  cin >> N;
  vector<double> R(N);
  rep(i, N) cin >> R[i];

  sort(all(R), greater<double>());

  double ans = 0;
  rep(i, N) {
    if (i % 2 == 0)
      ans += circle(R[i]);
    else
      ans -= circle(R[i]);
  }
  printf("%.10f\n", ans);
}