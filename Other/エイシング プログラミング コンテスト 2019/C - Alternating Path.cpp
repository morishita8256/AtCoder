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
  vector<vector<char>> S(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> S[i][j];
    }
  }

  vector<vector<bool>> visited(H, vector<bool>(W, false));

  typedef pair<int, int> P;

  ll ans = 0;
  rep(h, H) {
    rep(w, W) {
      if (visited[h][w])
        continue;

      queue<P> q;
      map<char, ll> m;
      q.push(P(h, w));
      visited[h][w] = true;
      m[S[h][w]]++;

      while (!q.empty()) {
        P now = q.front();
        q.pop();

        rep(d, 4) {
          int i = now.fi;
          int j = now.se;
          int ni = i + di[d];
          int nj = j + dj[d];
          if (ni < 0 || ni >= H || nj < 0 || nj >= W || visited[ni][nj])
            continue;
          if (S[i][j] == S[ni][nj])
            continue;

          m[S[ni][nj]]++;
          visited[ni][nj] = true;
          q.push(P(ni, nj));
        }
      }
      ans += m['#'] * m['.'];
    }
  }

  cout << ans << endl;
}