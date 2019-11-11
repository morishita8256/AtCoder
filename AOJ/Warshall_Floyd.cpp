#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ((ll)(x).size())
typedef long long ll;
const ll LINF = 1001001001001001001ll;

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
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja
*/


int main() {
  int V, E;
  cin >> V >> E;

  vector<ll> s(E), t(E), d(E);
  rep(i, E) {
    cin >> s[i] >> t[i] >> d[i];
  }


  vector<vector<ll>> dist(V, vector<ll>(V, LINF));
  rep(i, V) {
    dist[i][i] = 0;
  }
  rep(i, E) {
    ll from, to, cost;
    from = s[i], to = t[i], cost = d[i];
    dist[from][to] = cost;
    // dist[to][from] = cost;
  }

  warshal_floyd(dist);

  // 負閉路検出
  rep(i, V) {
    if (dist[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }


  rep(i, sz(dist)) {
    rep(j, sz(dist[0])) {
      if (dist[i][j] == LINF)
        cout << "INF";
      else
        cout << dist[i][j];

      cout << (j == sz(dist[0]) - 1 ? "\n" : " ");
    }
  }
}