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

int N;
typedef pair<int, int> P;

P i_j(int p) {
  return P(p / N, p % N);
}

signed main() {
  cin >> N;

  int M = N * N;
  vector<int> p(M);
  rep(i, M) {
    cin >> p[i];
    p[i]--;
  }

  vector<vector<int>> cnt(N, vector<int>(N, INF));
  rep(i, N) {
    rep(j, N) {
      chmin(cnt[i][j], i);
      chmin(cnt[i][j], N - 1 - i);
      chmin(cnt[i][j], j);
      chmin(cnt[i][j], N - 1 - j);
    }
  }

  vector<vector<bool>> is_occupied(N, vector<bool>(N, true));


  int di[4] = {0, -1, 0, 1}, dj[4] = {1, 0, -1, 0};

  int ans = 0;
  rep(k, M) {
    P now = i_j(p[k]);
    int i = now.fi, j = now.se;
    ans += cnt[i][j];

    is_occupied[i][j] = false;

    queue<P> q;
    q.push(now);

    while (!q.empty()) {
      auto now = q.front();
      int i = now.fi, j = now.se;
      q.pop();

      rep(d, 4) {
        int ni = i + di[d], nj = j + dj[d];
        if (ni < 0 || ni >= N || nj < 0 || nj >= N)
          continue;
        if (chmin(cnt[ni][nj], cnt[i][j] + is_occupied[i][j]))
          q.push(P(ni, nj));
      }
    }
  }
  cout << ans << endl;
}