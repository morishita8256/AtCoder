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

struct edge {
  ll to, cost;
  edge(ll to, ll cost) : to(to), cost(cost) {
  }
};


typedef pair<ll, int> P;  // <最短距離, 頂点の番号>

/* 負閉路の検出はできない。O(E logV) */
/* 負の辺があってもダメ */
void dijkstra(int V, int E, vector<vector<edge>>& G, vector<ll>& dist, int s) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(dist.begin(), dist.end(), LINF);
  dist[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (dist[v] < p.first)
      continue;

    for (int i = 0; i < G[v].size(); ++i) {
      edge e = G[v][i];
      if (dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        que.push(P(dist[e.to], e.to));
      }
    }
  }
}

signed main() {
  int N;
  cin >> N;
  vector<int> a(N - 1), b(N - 1);
  rep(i, N - 1) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }

  int V, E;

  V = N, E = N - 1;

  vector<vector<edge>> G(V);
  for (int i = 0; i < E; i++) {
    ll from, to, cost;
    from = a[i], to = b[i], cost = 1;
    G[from].push_back(edge(to, cost));
    G[to].push_back(edge(from, cost));
  }
  vector<ll> dist(V);
  dijkstra(V, E, G, dist, 0);

  int e = 0, o = 0;
  rep(i, N) {
    if (dist[i] % 2)
      o++;
    else
      e++;
  }

  vector<int> ans(N);

  if (o <= N / 3) {
    int temp = 3;
    vector<bool> used(N + 1, false);

    rep(i, N) {
      if (dist[i] % 2) {
        ans[i] = temp;
        used[temp] = true;
        temp += 3;
      }
    }

    int num = 1;
    rep(i, N) {
      if (ans[i] != 0)
        continue;
      while (used[num]) {
        num++;
      }
      ans[i] = num;
      used[num] = true;
    }

  } else if (e <= N / 3) {
    int temp = 3;
    vector<bool> used(N + 1, false);

    rep(i, N) {
      if (dist[i] % 2 == 0) {
        ans[i] = temp;
        used[temp] = true;
        temp += 3;
      }
    }

    int num = 1;
    rep(i, N) {
      if (ans[i] != 0)
        continue;
      while (used[num]) {
        num++;
      }
      ans[i] = num;
      used[num] = true;
    }
  } else {
    int temp = 1;
    vector<bool> used(N + 1, false);

    rep(i, N) {
      if (dist[i] % 2) {
        ans[i] = temp;
        used[temp] = true;
        temp += 3;
        if (temp > N)
          break;
      }
    }

    temp = 2;
    rep(i, N) {
      if (dist[i] % 2 == 0) {
        ans[i] = temp;
        used[temp] = true;
        temp += 3;
        if (temp > N)
          break;
      }
    }

    int num = 1;
    rep(i, N) {
      if (ans[i] != 0)
        continue;
      while (used[num]) {
        num++;
      }
      ans[i] = num;
      used[num] = true;
    }
  }
  
  cout << ans << endl;
}