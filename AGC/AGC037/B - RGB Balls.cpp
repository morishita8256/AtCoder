#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 998244353;

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
  mint(ll x = 0) : x((x % MOD + MOD) % MOD) {}
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
  string S;
  cin >> S;
  int M = S.size();
  S.pb('x');

  vector<ll> fact(N + 1);
  fact[0] = 1;
  fact[1] = 1;
  repp(i, 2, N) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }

  vector<int> rgb(3);
  map<char, int> m;
  m['R'] = 0;
  m['G'] = 1;
  m['B'] = 2;

  mint ans = 1;
  rep(i, M) {
    char now = S[i];
    rgb[m[now]]++;
    int x = rgb[m[now]];
    int y = rgb[(m[now] + 1) % 3];
    int z = rgb[(m[now] + 2) % 3];

    if (y < z)
      swap(y, z);

    if (x > y) {
      int temp = x - y;
      ans *= temp;
    } else if (x <= y && x > z) {
      int temp = x - z;
      ans *= temp;
    }
  }
  ans *= fact[N];
  cout << ans.x << endl;
}