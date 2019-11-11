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

vector<vector<char>> c;
vector<vector<ll>> dist;


int H, W;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
map<char, int> dir = {{'R', 0}, {'D', 1}, {'L', 2}, {'U', 3}};


int main() {
  int R, C;
  cin >> R >> C;
  int sy, sx;
  cin >> sy >> sx;
  int gy, gx;
  cin >> gy >> gx;
  sx--, sy--;
  gx--, gy--;

  H = R, W = C;

  c = vector<vector<char>>(R, vector<char>(C));
  rep(i, R) {
    rep(j, C) {
      cin >> c[i][j];
    }
  }

  dist = vector<vector<ll>>(R, vector<ll>(C, LINF));

  typedef pair<int, int> P;
  queue<P> q;

  q.push(P(sy, sx));
  dist[sy][sx] = 0;
  while (!q.empty()) {
    P now = q.front();
    q.pop();

    rep(i, 4) {
      int y = now.fi, x = now.se;
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W)
        continue;
      if (c[ny][nx] == '#')
        continue;
      ll nd = dist[y][x] + 1;
      if (chmin(dist[ny][nx], nd))
        q.push(P(ny, nx));
    }
  }
  cout << dist[gy][gx] << endl;
}