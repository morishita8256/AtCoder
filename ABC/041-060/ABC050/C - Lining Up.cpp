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
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  vector<int> cnt(N);
  rep(i, N) {
    cnt[A[i]]++;
  }

  if (N % 2 == 0) {
    for (int i = 1; i < N; i += 2) {
      if (cnt[i] != 2) {
        cout << 0 << endl;
        return 0;
      }
    }
  } else {
    if (cnt[0] != 1) {
      cout << 0 << endl;
      return 0;
    }
    for (int i = 2; i < N; i += 2) {
      if (cnt[i] != 2) {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  mint ans = 2;
  ans = ans.pow(N / 2);
  cout << ans.x << endl;
}