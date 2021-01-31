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

struct stone {
  ll l, r, p;
  stone() = default;
  stone(ll l, ll r, ll p) : l(l), r(r), p(p) {
  }

  bool operator<(const stone& another) const {
    return l < another.l;
  };
};


signed main() {
  int N, W, C;
  cin >> N >> W >> C;
  vector<int> l(N), r(N), p(N);
  rep(i, N) {
    cin >> l[i] >> r[i] >> p[i];
  }

  typedef pair<int, int> P;
  vector<P> imos;

  rep(i, N) {
    int L = l[i] - C;
    imos.pb(P(L, p[i]));

    int R = r[i];
    imos.pb(P(R, -p[i]));
  }
  imos.pb(P(0, 0));
  imos.pb(P(W - C, 0));
  sort(all(imos));

  int ans = INF;
  int ind = 0;
  int sum = 0;

  int M = len(imos);
  rep(i, M) {
    int x = imos[i].fi, d = imos[i].se;
    sum += d;
    if (d <= 0 && 0 <= x && x <= W - C)
      chmin(ans, sum);
  }
  cout << ans << endl;
}