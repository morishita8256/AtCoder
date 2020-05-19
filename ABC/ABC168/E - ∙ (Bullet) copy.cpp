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

#pragma region mod
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

  // 入出力
  friend ostream& operator<<(ostream& s, const mint a) {
    s << a.x;
    return s;
  }
  friend istream& operator>>(istream& s, mint& a) {
    s >> a.x;
    return s;
  }
};

/* a^n (MOD) の計算 O(log n) */
ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}

// a^{-1} mod を計算する
ll modinv(ll a) {
  return modpow(a, MOD - 2);
}
#pragma endregion

typedef pair<int, int> P;

P reduce(P p) {
  int g = gcd(p.fi, p.se);
  if (g == 0)
    return P(0, 0);

  p.fi /= g, p.se /= g;
  if (p.fi < 0 || p.fi == 0 && p.se < 0) {
    p.fi *= -1;
    p.se *= -1;
  }
  return p;
}

P ng(P p) {
  P temp = P(p.se, -p.fi);
  return reduce(temp);
}

signed main() {
  int N;
  cin >> N;

  map<P, int> m;
  int n00 = 0;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    auto p = reduce(P(a, b));
    if (p.fi != 0 || p.se != 0)
      m[p]++;
    else
      n00++;
  }

  set<P> seen;
  mint ans = 1;

  for (auto item : m) {
    auto p1 = item.fi;
    int num1 = item.se;
    if (seen.find(p1) != seen.end())
      continue;

    auto p2 = ng(p1);

    int num2 = (m.find(p2) == m.end()) ? 0 : m[p2];
    ans *= modpow(2, num1) + modpow(2, num2) - 1;

    seen.insert(p1);
    seen.insert(p2);
  }

  ans -= 1;
  ans += n00;
  cout << ans << endl;
}