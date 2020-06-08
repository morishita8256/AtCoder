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


signed main() {
  int N, M;
  cin >> N >> M;
  vector<int> u(M), v(M);

  vector<vector<int>> g(N);
  rep(i, M) {
    cin >> u[i] >> v[i];
    u[i]--, v[i]--;
    g[u[i]].pb(v[i]);
    g[v[i]].pb(u[i]);
  }

  int single = 0, bipart = 0, not_bipart = 0;

  vector<int> color(N, -1);
  rep(i, N) {
    if (len(g[i]) == 0) {
      single++;
      continue;
    }

    if (color[i] != -1)
      continue;

    bool is_bipart = true;
    queue<int> q;
    q.push(i);
    color[i] = 0;
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      int c = color[i];

      int nc = 1 - c;
      for (int ni : g[i]) {
        if (color[ni] == -1) {
          color[ni] = nc;
          q.push(ni);
        } else if (color[ni] != nc) {
          is_bipart = false;
        }
      }
    }

    (is_bipart ? bipart : not_bipart)++;
  }

  int not_single = N - single;

  int ans = 0;
  ans += single * not_single * 2 + single * single;
  ans += bipart * bipart * 2;
  ans += bipart * not_bipart * 2;
  ans += not_bipart * not_bipart;

  cout << ans << endl;
}