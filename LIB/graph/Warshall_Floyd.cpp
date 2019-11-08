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

void warshal_floyd(vector<vector<ll>>& dist) {
  int V = dist.size();
  rep(k, V) {
    rep(i, V) {
      rep(j, V) {
        // 負の辺のために必要なif文
        if (dist[i][k] != LINF && dist[k][j] != LINF)
          chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
*/

int main() {
  int V, E;
  cin >> V >> E;
  vector<int> s(E), t(E), d(E);
  rep(i, E) cin >> s[i] >> t[i] >> d[i];

  vector<vector<ll>> dist(V, vector<ll>(V, LINF));
  rep(i, V) {
    dist[i][i] = 0;
  }
  rep(i, E) {
    dist[s[i]][t[i]] = d[i];  // 有向
  }

  warshal_floyd(dist);
  auto dist_ans = dist;
  warshal_floyd(dist);

  rep(i, V) {
    rep(j, V) {
      if (dist[i][j] != dist_ans[i][j]) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
      }
    }
  }

  rep(i, V) {
    rep(j, V) {
      if (dist_ans[i][j] == LINF)
        cout << "INF";
      else
        cout << dist_ans[i][j];
      cout << ((j == V - 1) ? '\n' : ' ');
    }
  }
}