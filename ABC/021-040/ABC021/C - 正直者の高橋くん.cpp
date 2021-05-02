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


void warshal_floyd(vector<vector<ll>>& dist) {
  int V = dist.size();
  rep(k, V) {
    rep(i, V) {
      rep(j, V) {
        // 負の辺のために必要なif文
        if (dist[i][k] != LINF && dist[k][j] != LINF)
          chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
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

int main() {
  int N;
  cin >> N;
  int a, b;
  cin >> a >> b;
  a--, b--;
  int M;
  cin >> M;
  vector<int> x(M), y(M);
  rep(i, M) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
  }

  int V = N, E = M;
  vector<vector<ll>> dist(V, vector<ll>(V, LINF));
  rep(i, V) {
    dist[i][i] = 0;
  }
  rep(i, E) {
    dist[x[i]][y[i]] = 1;  // 有向
    dist[y[i]][x[i]] = 1;  // 有向
  }

  warshal_floyd(dist);
  ll D = dist[a][b];
  vector<ll> num(D + 1, 0);
  rep(i, N) {
    if (dist[a][i] + dist[i][b] == D)
      num[dist[a][i]]++;
  }

  mint ans = 1;
  rep(i, D + 1) {
    ans *= num[i];
  }
  cout << ans.x << endl;
}