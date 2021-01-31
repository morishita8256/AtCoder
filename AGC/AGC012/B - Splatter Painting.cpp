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
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
#define int long long
typedef long long ll;
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

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

vector<int> dmax, ans;
vector<vector<int>> G;

void dfs(int v, int d, int c) {
  if (d <= dmax[v])
    return;

  dmax[v] = d;
  if (ans[v] == 0)
    ans[v] = c;
  for (int nv : G[v]) {
    dfs(nv, d - 1, c);
  }
}

signed main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  G = vector<vector<int>>(N);

  rep(i, M) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    G[a[i]].pb(b[i]);
    G[b[i]].pb(a[i]);
  }

  int Q;
  cin >> Q;
  vector<int> v(Q), d(Q), c(Q);
  rep(i, Q) {
    cin >> v[i] >> d[i] >> c[i];
    v[i]--;
  }

  reverse(all(v));
  reverse(all(d));
  reverse(all(c));

  dmax = vector<int>(N, -1);
  ans = vector<int>(N);
  rep(i, Q) {
    dfs(v[i], d[i], c[i]);
  }

  rep(i, len(ans)) {
    cout << ans[i] << endl;
  }
}