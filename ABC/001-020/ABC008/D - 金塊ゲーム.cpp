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

struct rect {
  ll l, r, u, d;
  string s;
  rect() = default;
  rect(ll l, ll r, ll u, ll d) : l(l), r(r), u(u), d(d) {
    s += to_string(l);
    s += "_";
    s += to_string(r);
    s += "_";
    s += to_string(u);
    s += "_";
    s += to_string(d);
  }
  bool operator<(const rect& another) const {
    return s < another.s;
  };
};


int W, H, N;
vector<int> X, Y;
map<rect, int> m;

int dfs(rect R) {
  if (m.find(R) != m.end())
    return m[R];

  int mx = 0;

  rep(i, N) {
    if (R.l <= X[i] && X[i] <= R.r && R.u <= Y[i] && Y[i] <= R.d) {
      int temp = R.r - R.l + R.d - R.u + 1;
      temp += dfs(rect(R.l, X[i] - 1, R.u, Y[i] - 1));
      temp += dfs(rect(X[i] + 1, R.r, R.u, Y[i] - 1));
      temp += dfs(rect(R.l, X[i] - 1, Y[i] + 1, R.d));
      temp += dfs(rect(X[i] + 1, R.r, Y[i] + 1, R.d));
      chmax(mx, temp);
    }
  }

  m[R] = mx;
  return mx;
}

signed main() {
  cin >> W >> H;
  cin >> N;
  X = vector<int>(N);
  Y = vector<int>(N);
  rep(i, N) {
    cin >> X[i] >> Y[i];
    X[i]--, Y[i]--;
  }

  int ans = dfs(rect(0, W - 1, 0, H - 1));
  cout << ans << endl;
}