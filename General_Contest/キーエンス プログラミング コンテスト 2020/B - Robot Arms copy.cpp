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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}


struct Robot {
  ll X, L, r, l;
  Robot(ll X, ll L) : X(X), L(L) {
    l = X - L, r = X + L;
  }

  bool operator<(const Robot& another) const {
    return r < another.r;
  };
};


signed main() {
  ll N;
  cin >> N;

  vector<Robot> Robots;
  rep(i, N) {
    ll X, L;
    cin >> X >> L;
    Robots.pb(Robot(X, L));
  }


  sort(all(Robots));
  ll temp = -LINF;
  int ans = 0;
  rep(i, N) {
    if (Robots[i].l >= temp) {
      ans++;
      temp = Robots[i].r;
    }
  }
  cout << ans << "\n";
}