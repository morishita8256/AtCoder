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
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
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

signed main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<char>> A(H, vector<char>(W));

  int si, sj;
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
      if (A[i][j] == 'S') {
        si = i, sj = j;
      }
    }
  }

  vector<vector<int>> dist(H, vector<int>(W, INF));
  queue<int> q;

  vector<int> di = {0, -1, 0, 1}, dj = {1, 0, -1, 0};


  dist[si][sj] = 0;
  q.push(si * W + sj);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    int ci = cur / W, cj = cur % W;
    rep(d, 4) {
      int ni = ci + di[d], nj = cj + dj[d];
      if (ni < 0 || H <= ni || nj < 0 || W <= nj || A[ni][nj] == '#')
        continue;
      if (chmin(dist[ni][nj], dist[ci][cj] + 1))
        q.push(ni * W + nj);
    }
  }

  int ans = INF;
  rep(i, H) {
    rep(j, W) {
      if (dist[i][j] > K)
        continue;
      int nearest = min({i - 0, j - 0, H - 1 - i, W - 1 - j});
      int temp = 1 + (nearest + K - 1) / K;
      chmin(ans, temp);
    }
  }

  cout << ans << endl;
}