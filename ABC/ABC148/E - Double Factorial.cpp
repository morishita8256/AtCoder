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


int main() {
  ll N;
  cin >> N;

  if (N % 2) {
    cout << 0 << endl;
    return 0;
  }

  ll num2 = 0;
  ll base2 = 2;

  ll N2 = N;
  while (base2 <= N) {
    num2 += N2 / base2;
    base2 *= 2;
  }

  ll num5 = 0;
  ll base5 = 5;

  ll N5 = N;
  while (base5 <= N) {
    num5 += (N5 / base5) / 2;
    base5 *= 5;
  }

  ll ans = min(num2, num5);
  cout << ans << endl;
}