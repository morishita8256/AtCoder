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

signed main() {
  int H, W;
  cin >> H >> W;
  int sy, sx, gy, gx;
  vector<vector<char>> c(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> c[i][j];
      if (c[i][j] == 's') {
        sy = i, sx = j;
      }
      if (c[i][j] == 'g') {
        gy = i, gx = j;
      }
    }
  }

  int dy[4] = {0, 1, 0, -1};
  int dx[4] = {1, 0, -1, 0};


  vector<vector<int>> dist(H, vector<int>(W, LINF));

  typedef pair<int, int> P;
  deque<P> q;

  q.push_back(P(sy, sx));
  dist[sy][sx] = 0;
  while (!q.empty()) {
    P now = q.front();
    q.pop_front();

    rep(i, 4) {
      int y = now.fi, x = now.se;
      int ny = y + dy[i], nx = x + dx[i];

      // inside maze
      if (ny < 0 || ny >= H || nx < 0 || nx >= W)
        continue;

      if (c[ny][nx] == '#') {
        if (chmin(dist[ny][nx], dist[y][x] + 1))
          q.push_back(P(ny, nx));
      } else {
        if (chmin(dist[ny][nx], dist[y][x]))
          q.push_front(P(ny, nx));
      }
    }
  }
  if (dist[gy][gx] <= 2)
    cout << "YES\n";
  else
    cout << "NO\n";
}