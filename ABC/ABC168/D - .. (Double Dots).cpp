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
#define int long long
typedef long long ll;
#define double long double
typedef double ld;
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
#pragma endregion

signed main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  vector<vector<int>> G(N);
  rep(i, M) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
    G[A[i]].pb(B[i]);
    G[B[i]].pb(A[i]);
  }

  typedef pair<int, int> P;  // now, prev
  queue<P> q;

  vector<int> par(N, -1);
  q.push(P(-2, 0));

  while (!q.empty()) {
    auto p = q.front();
    q.pop();

    int now = p.se, prev = p.fi;

    for (int next : G[now]) {
      if (par[next] != -1)
        continue;
      par[next] = now;
      q.push(P(now, next));
    }
  }

  vector<int> ans(N - 1);

  repp(i, 1, N - 1) {
    if (par[i] == -1) {
      cout << "No\n";
      return 0;
    }
    ans[i - 1] = par[i] + 1;
  }

  cout << "Yes\n";
  rep(i, len(ans)) {
    cout << ans[i] << endl;
  }
}