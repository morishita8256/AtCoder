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

ll f(ll b, ll n) {
  if (n < b)
    return n;
  else
    return f(b, n / b) + n % b;
}

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
  ll n;
  cin >> n;
  ll s;
  cin >> s;

  if (n == s) {
    cout << n + 1 << endl;
    return 0;
  }

  if (s > (n + 1) / 2) {
    cout << -1 << endl;
    return 0;
  }


  repp(b, 2, sqrt(n) + 1) {
    if (f(b, n) == s) {
      cout << b << endl;
      return 0;
    }
  }

  auto divs = divisor(n - s);
  for (auto b : divs) {
    ll p = (n - s) / b;

    b++;
    if (b < sqrt(n))
      continue;

    ll q = s - p;
    if (q < 0 || p >= b || q >= b)
      continue;

    cout << b << endl;
    return 0;
  }
}