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

int main() {
  int N, M, BB;
  cin >> N >> M >> BB;
  vector<vector<char>> field(N, vector<char>(N, '.'));

  int gy, gx;
  cin >> gy >> gx;
  field[gy][gx] = 'G';

  vector<int> ry(M), rx(M);
  vector<char> c(M);
  rep(i, M) {
    cin >> ry[i] >> rx[i] >> c[i];
    field[ry[i]][rx[i]] = c[i];
  }

  int by, bx;
  rep(i, BB) {
    cin >> by >> bx;
    field[by][bx] = 'B';
  }

  /* Direction */
  char DIR_gen[4] = {'R', 'D', 'L', 'U'};
  int dx_gen[4] = {1, 0, -1, 0};
  int dy_gen[4] = {0, 1, 0, -1};
  char inv_direction_gen[4] = {'L', 'U', 'R', 'D'};

  int max_score = 0;
  int ans_K;
  vector<vector<char>> ans_guide;
  vector<vector<bool>> ans_used;

  vector<int> iter = {0, 1, 2, 3};
  do {
    char DIR[4], inv_direction[4];
    int dx[4], dy[4];

    /* Order of direction */
    rep(g, 4) {
      int gg = iter[g];
      DIR[g] = DIR_gen[gg];
      dy[g] = dy_gen[gg];
      dx[g] = dx_gen[gg];
      inv_direction[g] = inv_direction_gen[gg];
    }
    map<char, int> dir;
    rep(m, 4) {
      dir[DIR[m]] = m;
    }

    vector<vector<char>> guide(N, vector<char>(N, '.'));

    /* BFS : put guides on the all floor */
    typedef pair<int, int> P;
    queue<P> q;
    q.push(mp(gy, gx));
    while (!q.empty()) {
      P now = q.front();
      q.pop();

      rep(i, 4) {
        int y = now.fi;
        int x = now.se;
        int ny = y + dy[i];
        ny = (ny + N) % N;
        int nx = x + dx[i];
        nx = (nx + N) % N;

        if (field[ny][nx] == 'B')
          continue;
        if (field[ny][nx] == 'G')
          continue;
        if (guide[ny][nx] != '.')
          continue;

        q.push(mp(ny, nx));
        guide[ny][nx] = inv_direction[i];
      }
    }

    int A = 0, B = 0, C = 0;
    /* Check whether each guide is necessary */
    vector<vector<bool>> used(N, vector<bool>(N, false));
    vector<vector<bool>> visited(N, vector<bool>(N, false));  // for C

    rep(i, M) {
      set<P> s;
      vector<P> use;

      int y = ry[i], x = rx[i];
      if (guide[y][x] == '.') {
        continue;
      }
      if (guide[y][x] != c[i]) {
        use.pb(P(y, x));
      }
      visited[y][x] = true;
      s.insert(P(y, x));

      while (true) {
        char now_dir = guide[y][x];
        int ny = y + dy[dir[now_dir]];
        ny = (ny + N) % N;
        int nx = x + dx[dir[now_dir]];
        nx = (nx + N) % N;

        visited[ny][nx] = true;

        if (ny == gy && nx == gx) {
          A++;
          rep(u, sz(use)) {
            used[use[u].fi][use[u].se] = true;
          }
          break;
        }

        if (s.find(P(ny, nx)) != s.end()) {
          break;
        } else {
          s.insert(P(ny, nx));
        }

        char next_dir = guide[ny][nx];
        if (next_dir != now_dir) {
          use.pb(P(ny, nx));
        }
        y = ny;
        x = nx;
      }
    }

    /* Count K */
    int K = 0;
    rep(y, N) {
      rep(x, N) {
        if (used[y][x])
          K++;
        if (visited[y][x])
          C++;
      }
    }

    B = K;

    int score = 1000 * A - 10 * B + C;
    if (chmax(max_score, score)) {
      ans_K = K;
      ans_guide = guide;
      ans_used = used;
    }
  } while (next_permutation(all(iter)));

  /* Output */
  cout << ans_K << endl;
  rep(y, N) {
    rep(x, N) {
      if (ans_guide[y][x] == '.')
        continue;
      if (!ans_used[y][x])
        continue;
      cout << y << ' ' << x << ' ' << ans_guide[y][x] << endl;
    }
  }

  // ofstream o("test.txt");
  // o << ans_K << endl;
  // rep(y, N) {
  //   rep(x, N) {
  //     if (ans_guide[y][x] == '.')
  //       continue;
  //     if (!ans_used[y][x])
  //       continue;
  //     o << y << ' ' << x << ' ' << ans_guide[y][x] << endl;
  //   }
  // }
}