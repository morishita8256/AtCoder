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

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}


int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> a(N);
  rep(i, N) {
    cin >> a[i];
    a[i] /= 2;
  }

  set<int> s;
  rep(i, N) {
    ll temp = a[i];
    int cnt = 0;
    while (temp % 2 == 0) {
      cnt++;
      temp /= 2;
    }
    s.insert(cnt);
  }

  if (sz(s) > 1) {
    cout << 0 << endl;
    return 0;
  }


  ll LCM = 1;
  rep(i, N) {
    LCM = lcm(LCM, a[i]);

    if (LCM > M) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = M / LCM;
  ans = (ans + 1) / 2;

  cout << ans << endl;
}