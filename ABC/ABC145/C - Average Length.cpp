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
  int N;
  cin >> N;
  vector<double> x(N), y(N);
  rep(i, N) {
    cin >> x[i] >> y[i];
  }

  vector<int> p(N);
  rep(i, N) {
    p[i] = i;
  }

  double ans = 0.0;
  int cnt = 0;
  do {
    cnt++;
    double temp = 0.0;
    rep(i, N - 1) {
      temp += dist(x[p[i]], y[p[i]], x[p[i + 1]], y[p[i + 1]]);
    }
    ans += temp;
  } while (next_permutation(all(p)));
  ans /= cnt;
  printf("%.14f\n", ans);  // Lf?
}