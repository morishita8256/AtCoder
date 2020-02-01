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
#define debug(var) cout << "[" << #var << "]\n" << var << "\n\n"
typedef long long ll;
const int INF = 1001001001;
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
      cout << '\n';
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

int N, ind;
vector<ll> c;
vector<int> ans;
vector<vector<int>> G;

void dfs(int now) {
  ans[now] = c[ind++];
  for (int next : G[now]) {
    if (ans[next] != -1)
      continue;
    dfs(next);
  }
}

signed main() {
  cin >> N;
  vector<int> a(N - 1), b(N - 1);
  rep(i, N - 1) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }

  c = vector<ll>(N);
  rep(i, N) {
    cin >> c[i];
  }
  sort(all(c), greater<ll>());

  ll M = 0;
  repp(i, 1, N - 1) {
    M += c[i];
  }
  cout << M << "\n";

  G = vector<vector<int>>(N);
  rep(i, N - 1) {
    G[a[i]].pb(b[i]);
    G[b[i]].pb(a[i]);
  }

  ans = vector<int>(N, -1);
  ind = 0;

  dfs(0);
  cout << ans << "\n";
}