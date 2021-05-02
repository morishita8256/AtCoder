#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

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

#define int ll

signed main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> a(N), b(N);
  rep(i, N - 1) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  vector<int> p(Q), x(Q);
  rep(i, Q) {
    cin >> p[i] >> x[i];
    p[i]--;
  }

  vector<vector<int>> G(N);
  rep(i, N) {
    G[a[i]].pb(b[i]);
    G[b[i]].pb(a[i]);
  }

  vector<int> count(N);
  rep(i, Q) {
    count[p[i]] += x[i];
  }
  
  vector<int> visited(N, false);

  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    visited[now] = true;

    for (int next : G[now]) {
      if (visited[next])
        continue;
      count[next] += count[now];
      q.push(next);
    }
  }

  rep(i, N) {
    cout << count[i] << ' ';
  }
  cout << endl;
}