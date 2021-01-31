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
#define sz(x) ((int)(x).size())
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

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
    }
  }

  vector<vector<int>> dist(H, vector<int>(W, INF));

  typedef pair<int, int> P;
  queue<P> q;
  rep(i, H) {
    rep(j, W) {
      if (A[i][j] == '#') {
        q.push(P(i, j));
        dist[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    P now = q.front();
    q.pop();

    rep(d, 4) {
      int i = now.fi;
      int j = now.se;
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 0 || ni >= H || nj < 0 || nj >= W || dist[ni][nj] != INF)
        continue;

      dist[ni][nj] = dist[i][j] + 1;
      q.push(P(ni, nj));
    }
  }

  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      chmax(ans, dist[i][j]);
    }
  }
  cout << ans << endl;
}
