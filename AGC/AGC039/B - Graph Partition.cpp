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

int N;
vector<vector<int>> G;

int bfs(int s) {
  queue<int> q;
  vector<int> k(N, -1);

  q.push(s);
  k[s] = 0;

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (int next : G[now]) {
      if (k[next] != -1) {
        if (abs(k[next] - k[now]) != 1) {
          return -1;
        }
      } else {
        k[next] = k[now] + 1;
        q.push(next);
      }
    }
  }


  int res = 0;
  rep(i, N) {
    chmax(res, k[i]);
  }

  res++;
  return res;
}


signed main() {
  cin >> N;
  vector<vector<char>> S(N, vector<char>(N));
  rep(i, N) {
    rep(j, N) {
      cin >> S[i][j];
    }
  }

  G = vector<vector<int>>(N);
  rep(i, N) {
    rep(j, N) {
      if (S[i][j] == '1')
        G[i].pb(j);
    }
  }

  int ans = -1;
  rep(i, N) {
    chmax(ans, bfs(i));
  }

  cout << ans << "\n";
}