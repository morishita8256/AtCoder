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

bool kousa(double ax,
           double ay,
           double bx,
           double by,
           double cx,
           double cy,
           double dx,
           double dy) {
  auto ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
  auto tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
  auto tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
  auto td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);

  // return tc * td < 0 && ta * tb < 0;
  return tc * td <= 0 && ta * tb <= 0;  // 端点を含む場合
};

int main() {
  double Ax, Ay;
  cin >> Ax >> Ay;
  double Bx, By;
  cin >> Bx >> By;

  int N;
  cin >> N;
  vector<double> X(N + 1), Y(N + 1);
  rep(i, N) {
    cin >> X[i] >> Y[i];
  }
  X[N] = X[0], Y[N] = Y[0];

  int ans = 0;
  rep(i, N) {
    double x1 = X[i], x2 = X[i + 1];
    double y1 = Y[i], y2 = Y[i + 1];
    double x3 = Ax, x4 = Bx;
    double y3 = Ay, y4 = By;
    if (kousa(x1, y1, x2, y2, x3, y3, x4, y4))
      ans++;
  }
  ans /= 2;
  ans++;
  cout << ans << endl;
}