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
#define debug(var) cout << "[" << #var << "]\n" << var << "\n"
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


signed main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);

  vector<int> A(M), B(M);
  rep(i, M) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
    G[A[i]].pb(B[i]);
  }

  int sz = INF;
  vector<int> ans;

  rep(i, M) {
    int s = B[i], g = A[i];
    vector<int> dist(N, -1);
    vector<int> back(N, -1);
    back[s] = g;
    dist[s] = 0;

    queue<int> q;
    q.push(s);


    while (!q.empty()) {
      int now = q.front();
      q.pop();

      for (auto next : G[now]) {
        if (dist[next] != -1)
          continue;
        dist[next] = dist[now] + 1;
        q.push(next);
        back[next] = now;
      }
    }

    if (dist[g] == -1)
      continue;

    int temp = dist[g] + 1;
    if (chmin(sz, temp)) {
      ans.clear();
      rep(j, temp) {
        ans.pb(g);
        g = back[g];
      }
    }
  }

  if (sz == INF) {
    cout << -1 << '\n';
    return 0;
  }

  cout << sz << "\n";
  rep(i, len(ans)) {
    cout << (ans[i] + 1) << "\n";
  }
}