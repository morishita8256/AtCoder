#pragma region head
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
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-7;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}
#pragma endregion

double find_min(double l, double r, bool f(double)) {
  double c;
  int cnt = 100;
  while (abs(r - l) > EPS && cnt-- > 0) {
    c = (r + l) / 2.0;
    if (f(c)) {
      r = c;
    } else {
      l = c;
    }
  }

  return r;
}

int N;
vector<double> x, y, c;

bool f(double trial) {
  double l = -INF, d = -INF, r = INF, u = INF;
  rep(i, N) {
    double h = trial / c[i];
    chmax(l, x[i] - h);
    chmax(d, y[i] - h);
    chmin(r, x[i] + h);
    chmin(u, y[i] + h);
  }
  return l <= r && d <= u;
}

signed main() {
  cin >> N;
  x = vector<double>(N);
  y = vector<double>(N);
  c = vector<double>(N);
  rep(i, N) {
    cin >> x[i] >> y[i] >> c[i];
  }

  double ans = find_min(0.0, 1e+9, f);
  cout << ans << endl;
}