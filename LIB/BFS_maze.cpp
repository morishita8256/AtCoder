#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
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


/*
https://atcoder.jp/contests/abc007/tasks/abc007_3
*/

vector<vector<char>> c;
vector<vector<ll>> dist;

int H, W;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
map<char, int> dir = {{'H', 0}, {'D', 1}, {'L', 2}, {'U', 3}};


int main() {
  int H, W;
  cin >> H >> W;
  int sy, sx;
  cin >> sy >> sx;
  sx--, sy--;
  int gy, gx;
  cin >> gy >> gx;
  gx--, gy--;

  c = vector<vector<char>>(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> c[i][j];
    }
  }

  dist = vector<vector<ll>>(H, vector<ll>(W, LINF));

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

      // inside maze
      if (y < 0 || y >= H || x < 0 || x >= W)
        continue;

      // not wall
      if (c[ny][nx] == '#')
        continue;

      ll nd = dist[y][x] + 1;

      // if 'dist' updated
      if (chmin(dist[ny][nx], nd))
        q.push(P(ny, nx));
    }
  }
  cout << dist[gy][gx] << endl;
}