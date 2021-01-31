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

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> s[i][j];
    }
  }

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  vector<vector<int>> d = vector<vector<int>>(H, vector<int>(W, INF));

  typedef pair<int, int> P;
  queue<P> q;
  q.push(make_pair(0, 0));
  d[0][0] = 0;

  while (!q.empty()) {
    P now = q.front();
    q.pop();

    rep(i, 4) {
      int y = now.fi;
      int x = now.se;
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (0 <= ny && ny < H && 0 <= nx && nx < W) {
        if (s[ny][nx] != '#' && d[ny][nx] == INF) {
          d[ny][nx] = d[y][x] + 1;
          P next = make_pair(ny, nx);
          q.push(next);
        }
      }
    }
  }

  if (d[H - 1][W - 1] == INF) {
    cout << -1 << endl;
    return 0;
  }

  int no_change = d[H - 1][W - 1] + 1;
  int cnt = 0;
  rep(i, H) {
    rep(j, W) {
      if (s[i][j] == '.')
        cnt++;
    }
  }
  int ans = cnt - no_change;
  cout << ans << endl;
}