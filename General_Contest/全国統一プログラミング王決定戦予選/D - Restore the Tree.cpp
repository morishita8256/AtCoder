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

vector<int> ans;


template <typename G>
vector<int> topological_sort(const G& g) {
  const int N = (int)g.size();
  vector<int> deg(N);
  for (int i = 0; i < N; i++) {
    for (auto& to : g[i])
      ++deg[to];
  }
  stack<int> st;
  for (int i = 0; i < N; i++) {
    if (deg[i] == 0)
      st.emplace(i);
  }
  vector<int> ord;
  while (!st.empty()) {
    auto p = st.top();
    st.pop();
    ord.emplace_back(p);
    for (auto& to : g[p]) {
      if (--deg[to] == 0) {
        st.emplace(to);
        ans[to] = p + 1;
      }
    }
  }
  return ord;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N - 1 + M), B(N - 1 + M);
  rep(i, N - 1 + M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }

  vector<vector<int>> G(N);
  rep(i, N - 1 + M) {
    G[A[i]].pb(B[i]);
  }

  ans = vector<int>(N);

  auto sorted = topological_sort(G);

  rep(i, len(ans)) {
    cout << ans[i] << endl;
  }
}