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
vector<vector<int>> d;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  int R, C;
  cin >> R >> C;
  int sy, sx;
  cin >> sy >> sx;
  int gy, gx;
  cin >> gy >> gx;

  sx--;
  sy--;
  gx--;
  gy--;

  c = vector<vector<char>>(R, vector<char>(C));
  rep(i, R) {
    rep(j, C) {
      cin >> c[i][j];
    }
  }

  d = vector<vector<int>>(R, vector<int>(C, INF));

  typedef pair<int, int> P;
  queue<P> q;

  P s = make_pair(sy, sx);

  q.push(s);
  d[sy][sx] = 0;
  while (!q.empty()) {
    P now = q.front();
    q.pop();

    rep(i, 4) {
      int y = now.fi;
      int x = now.se;
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (c[ny][nx] != '#' && d[ny][nx] == INF) {
        d[ny][nx] = d[y][x] + 1;
        P next = make_pair(ny, nx);
        q.push(next);
      }
    }
  }
  cout << d[gy][gx] << endl;
}