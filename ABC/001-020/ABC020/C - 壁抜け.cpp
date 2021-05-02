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
#define sz(x) ((ll)(x).size())
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

vector<vector<char>> s;
int H, W, T;
int sy, sx, gy, gx;


template <class T>
T find_max(T l, T r, bool f(T)) {
  T c;
  while (r - l > 1) {
    c = (r + l) / 2;
    if (f(c)) {
      l = c;
    } else {
      r = c;
    }
  }

  return l;
}

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool f(ll trial) {
  vector<vector<ll>> d(H, vector<ll>(W, LINF));

  typedef pair<int, int> P;
  queue<P> q;

  q.push(P(sy, sx));
  d[sy][sx] = 0;
  while (!q.empty()) {
    P now = q.front();
    q.pop();

    rep(i, 4) {
      int y = now.fi;
      int x = now.se;
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= H || nx >= W)
        continue;

      ll nd = d[y][x] + ((s[ny][nx] == '#') ? trial : 1);
      if (chmin(d[ny][nx], nd)) {
        q.push(P(ny, nx));
      }
    }
  }

  return (d[gy][gx] <= T);
}

int main() {
  cin >> H >> W >> T;
  s = vector<vector<char>>(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> s[i][j];
      if (s[i][j] == 'S') {
        sy = i, sx = j;
      } else if (s[i][j] == 'G') {
        gy = i, gx = j;
      }
    }
  }
  ll ans = find_max(0LL, (ll)T, f);
  cout << ans << endl;
}