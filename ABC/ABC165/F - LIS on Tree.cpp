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

typedef pair<int, int> P;  // index, original_value

int N;
vector<int> a, dp, ans;
vector<vector<int>> G;
stack<P> st;

void dfs(int par, int now) {
  int temp_a = a[now];
  auto iter = lower_bound(all(dp), temp_a);
  int ind = distance(dp.begin(), iter);
  st.push(P(ind, dp[ind]));
  dp[ind] = temp_a;

  iter = lower_bound(all(dp), INF);
  int inf_ind = distance(dp.begin(), iter);

  ans[now] = inf_ind;
  for (int next : G[now]) {
    if (next == par)
      continue;
    dfs(now, next);
  }

  auto ind_val = st.top();
  st.pop();
  dp[ind_val.fi] = ind_val.se;
}


signed main() {
  cin >> N;
  a.assign(N, 0);
  rep(i, N) {
    cin >> a[i];
  }

  G.assign(N, vector<int>(0));
  vector<int> u(N - 1), v(N - 1);
  rep(i, N - 1) {
    cin >> u[i] >> v[i];
    u[i]--, v[i]--;
    G[u[i]].pb(v[i]);
    G[v[i]].pb(u[i]);
  }


  ans.assign(N, 0);
  dp.assign(N, INF);

  dfs(-1, 0);
  rep(i, len(ans)) {
    cout << ans[i] << endl;
  }
}