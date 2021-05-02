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

#define sz(x) ((ll)(x).size())

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

int N;
vector<vector<int>> G;
vector<mint> f, g;

void dfs(int par, int now) {
  rep(i, G[now].size()) {
    int next = G[now][i];
    if (next != par) {
      dfs(now, next);
    }
  }

  f[now] = 1;
  g[now] = 1;

  rep(i, G[now].size()) {
    int next = G[now][i];
    if (next != par) {
      f[now] *= g[next];
      g[now] *= f[next];
    }
  }

  f[now] += g[now];
}


int main() {
  cin >> N;
  vector<int> a(N - 1), b(N - 1);
  G = vector<vector<int>>(N);
  f = vector<mint>(N);
  g = vector<mint>(N);
  rep(i, N - 1) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    G[a[i]].pb(b[i]);
    G[b[i]].pb(a[i]);
  }


  dfs(-1, 0);
  cout << f[0].x << endl;
}