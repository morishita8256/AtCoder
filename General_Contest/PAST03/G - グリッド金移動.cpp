#pragma region head
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
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

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
#pragma endregion

template <typename T>
struct nvector {
  int edge, tot;
  vector<T> vec;
  nvector(int edge) : edge(edge), tot(edge * 2 + 1), vec(tot) {
  }
  nvector(int edge, T init) : edge(edge), tot(edge * 2 + 1), vec(tot, init) {
  }
  T& operator[](int pos) {
    return vec[pos + edge];
  }
};

template <typename T>
ostream& operator<<(ostream& s, const nvector<T>& nvector) {
  s << nvector.vec;
  return s;
}

signed main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  int shift = 201;
  X += shift, Y += shift;

  int L = 403;
  vector<vector<char>> c(L, vector<char>(L, '.'));

  typedef pair<int, int> P;
  vector<int> x(N), y(N);
  rep(i, N) {
    cin >> x[i] >> y[i];
    x[i] += shift, y[i] += shift;
    c[x[i]][y[i]] = '#';
  }

  vector<int> dx = {1, 0, -1, 1, -1, 0};
  vector<int> dy = {1, 1, 1, 0, 0, -1};


  vector<vector<int>> dist(L, vector<int>(L, INF));

  queue<P> q;
  q.push(P(shift, shift));
  dist[shift][shift] = 0;

  while (!q.empty()) {
    auto now = q.front();
    q.pop();

    int cx = now.fi, cy = now.se;

    rep(d, 6) {
      int nx = cx + dx[d], ny = cy + dy[d];
      if (nx < 0 || L <= nx || ny < 0 || L <= ny)
        continue;
      if (c[nx][ny] == '#')
        continue;

      if (chmin(dist[nx][ny], dist[cx][cy] + 1))
        q.push(P(nx, ny));
    }
  }

  int ans = dist[X][Y];
  if (ans == INF)
    ans = -1;
  cout << ans << endl;
}