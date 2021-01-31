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
#define sz(x) ((int)(x).size())
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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  vector<ll> F(N);
  rep(i, N) cin >> F[i];

  sort(all(A));
  sort(all(F), greater<ll>());

  ll r = LINF;
  ll l = -1;

  while (r - l > 1) {
    ll c = (r + l) / 2;
    ll shugyo = 0;

    rep(i, N) {
      ll multi = A[i] * F[i];
      if (multi <= c)
        continue;
      multi -= c;
      multi = (multi + F[i] - 1) / F[i];
      shugyo += multi;
    }
    if (shugyo <= K) {
      r = c;
    } else {
      l = c;
    }
  }
  cout << r << endl;
}