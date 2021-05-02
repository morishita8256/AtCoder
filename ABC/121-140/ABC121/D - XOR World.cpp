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

ll g(ll B) {
  ll ans = 0;
  ll k = log2(B) + 1;
  rep(j, k) {
    ll i = j;
    ll temp = 0;
    if (i == 0) {
      if (B % 4 == 1 || B % 4 == 2)
        temp = 1;
    } else {
      if (B % (ll)(pow(2, i + 1)) >= (ll)pow(2, i)) {
        if (B % 2 == 0)
          temp = 1;
      }
    }
    ans += (ll)pow(2, i) * temp;
  }
  return ans;
}

int main() {
  ll A, B;
  cin >> A >> B;

  ll ans = g(B) ^ g(A - 1);

  cout << ans << endl;
}