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
#define sz(x) ((int)(x).size())
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

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N - 1 + M), B(N - 1 + M);
  rep(i, N - 1 + M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }

  vector<vector<int>> invG(N);
  rep(i, N - 1 + M) {
    invG[B[i]].pb(A[i]);
  }

  int root = 0;
  while (true) {
    if (sz(invG[root]) == 0)
      break;
    root = invG[root][0];
  }

  vector<vector<int>> G(N);
  rep(i, N - 1 + M) {
    G[A[i]].pb(B[i]);
  }

  vector<int> dist(N);
  vector<int> par(N);

  queue<int> q;
  q.push(root);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (int next : G[now]) {
      if (chmax(dist[next], dist[now] + 1)) {
        par[next] = now + 1;
        q.push(next);
      }
    }
  }

  rep(i, N) {
    cout << par[i] << endl;
  }
}