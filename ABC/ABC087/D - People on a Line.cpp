#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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

struct edge {
  ll to;
  int cost;
  edge(int to, ll cost) : to(to), cost(cost) {}
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> L(M), R(M), D(M);
  vector<vector<edge>> G(N);
  rep(i, M) {
    cin >> L[i] >> R[i] >> D[i];
    L[i]--;
    R[i]--;
    G[L[i]].pb(edge(R[i], D[i]));
    G[R[i]].pb(edge(L[i], -D[i]));
  }

  vector<ll> x(N, LINF);
  rep(i, N) {
    if (x[i] != LINF)
      continue;
    queue<int> q;
    q.push(i);
    x[i] = 0;

    while (!q.empty()) {
      int now = q.front();
      q.pop();

      for (edge& ed : G[now]) {
        if (x[ed.to] != LINF) {
          if (x[ed.to] != x[now] + ed.cost) {
            cout << "No" << endl;
            return 0;
          }
        } else {
          x[ed.to] = x[now] + ed.cost;
          q.push(ed.to);
        }
      }
    }
  }
  cout << "Yes" << endl;
}