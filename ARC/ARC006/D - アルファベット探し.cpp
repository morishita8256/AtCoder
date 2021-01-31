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

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> c(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> c[i][j];
    }
  }

  vector<vector<bool>> visited(H, vector<bool>(W, false));

  typedef pair<int, int> P;

  map<char, int> m;
  m['A'] = 0;
  m['B'] = 0;
  m['C'] = 0;

  vector<char> cnt_to_char(10000000);
  int b;
  repp(i, 1, 145) {
    b = 12 * i * i;
    cnt_to_char[b] = 'A';
    b = 16 * i * i;
    cnt_to_char[b] = 'B';
    b = 11 * i * i;
    cnt_to_char[b] = 'C';
  }

  rep(i, H) {
    rep(j, W) {
      if (c[i][j] == '.' || visited[i][j])
        continue;

      queue<P> q;
      q.push(make_pair(i, j));
      visited[i][j] = true;
      int cnt = 0;

      while (!q.empty()) {
        P now = q.front();
        q.pop();
        cnt++;

        rep(d, 8) {
          int y = now.fi;
          int x = now.se;
          int ny = y + dy[d];
          int nx = x + dx[d];
          if (c[ny][nx] == 'o' && !visited[ny][nx]) {
            P next = make_pair(ny, nx);
            q.push(next);
            visited[ny][nx] = true;
          }
        }
      }
      m[cnt_to_char[cnt]]++;
    }
  }
  cout << m['A'] << ' ' << m['B'] << ' ' << m['C'] << endl;
}