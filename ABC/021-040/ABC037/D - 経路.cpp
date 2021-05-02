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

/* mint、表示は変数名.x */
struct mint {
  ll x;
  mint(ll x = 0) : x((x % MOD + MOD) % MOD) {
  }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD - a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  /* 変数名.pow(n) */
  mint pow(ll t) const {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // 以降はMODが素数のみ
  mint inv() const {
    return pow(MOD - 2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};

int H, W;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
map<char, int> dir = {{'H', 0}, {'D', 1}, {'L', 2}, {'U', 3}};

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<ll>> a(H, vector<ll>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> a[i][j];
    }
  }

  vector<vector<mint>> dp(H, vector<mint>(W, 1));
  vector<vector<int>> in(H, vector<int>(W));


  typedef pair<int, int> P;
  queue<P> q;

  // 各点への流入数
  rep(y, H) {
    rep(x, W) {
      rep(i, 4) {
        int ny = y + dy[i], nx = x + dx[i];

        // inside maze
        if (ny < 0 || ny >= H || nx < 0 || nx >= W)
          continue;

        if (a[y][x] > a[ny][nx])
          in[y][x]++;
      }

      // 流入数0ならスタート地点に
      if (in[y][x] == 0)
        q.push(P(y, x));
    }
  }

  while (!q.empty()) {
    P now = q.front();
    q.pop();

    rep(i, 4) {
      int y = now.fi, x = now.se;
      int ny = y + dy[i], nx = x + dx[i];

      // inside maze
      if (ny < 0 || ny >= H || nx < 0 || nx >= W)
        continue;

      if (a[y][x] >= a[ny][nx])
        continue;

      // 進める場合は進行先の流入数を1減らす。
      dp[ny][nx] += dp[y][x];
      in[ny][nx]--;

      // 流入数が0であればこれ以上更新はされないため、queueに追加。
      if (in[ny][nx] == 0)
        q.push(P(ny, nx));
    }
  }

  mint ans = 0;
  rep(i, H) {
    rep(j, W) {
      ans += dp[i][j];
    }
  }
  cout << ans.x << endl;
}