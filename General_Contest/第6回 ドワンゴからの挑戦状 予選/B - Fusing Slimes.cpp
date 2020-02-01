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


  vector<int> x(N);
  rep(i, N) {
    cin >> x[i];
  }

  if (N == 2) {
    cout << (x[1] - x[0]) << endl;
    return 0;
  }

  N--;

  vector<mint> F(N + 5);
  F[0] = 1;
  rep(i, N + 3) {
    F[i + 1] = F[i] * (i + 1);
  }

  vector<mint> stir(N + 5);
  stir[0] = 0;
  rep(i, N + 3) {
    stir[i + 1] = stir[i] * (i + 1) + F[i];
  }


  vector<mint> fact(N);
  fact[N - 1] = 1;
  fact[N - 2] = N;
  repr(i, N - 3, 0) {
    fact[i] = fact[i + 1] * (i + 2);
  }

  vector<mint> k(N);
  rep(i, N) {
    k[i] = stir[i + 1] * fact[i];
  }

  mint ans = 0;
  rep(i, N) {
    ans += k[i] * (x[i + 1] - x[i]);
  }
  cout << ans.x << endl;
}