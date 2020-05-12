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
const double EPS = 1e-9;

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

double r(double x, double y) {
  return sqrt(pow(x, 2) + pow(y, 2));
}

signed main() {
  int N;
  cin >> N;

  double AGx = 0.0, AGy = 0.0;
  vector<double> Ax(N), Ay(N);
  rep(i, N) {
    cin >> Ax[i] >> Ay[i];
    AGx += Ax[i] / N, AGy += Ay[i] / N;
  }

  vector<double> Ar(N);
  rep(i, N) {
    Ax[i] -= AGx, Ay[i] -= AGy;
    Ar[i] = r(Ax[i], Ay[i]);
  }
  sort(all(Ar), greater<double>());

  double Armax = Ar[0];


  double BGx = 0.0, BGy = 0.0;
  vector<double> Bx(N), By(N);
  rep(i, N) {
    cin >> Bx[i] >> By[i];
    BGx += Bx[i] / N, BGy += By[i] / N;
  }

  vector<double> Br(N);
  rep(i, N) {
    Bx[i] -= BGx, By[i] -= BGy;
    Br[i] = r(Bx[i], By[i]);
  }
  sort(all(Br), greater<double>());

  double Brmax = Br[0];

  double ans = Brmax / Armax;
  cout << ans << endl;
}