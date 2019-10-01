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

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  ll keta = 0;
  rep(i, N) {
    cin >> A[i];
    chmax(keta, (ll)(log2(A[i]) + 1));
  }
  chmax(keta, (ll)(log2(K) + 1));

  vector<ll> num_of_zero(keta);
  rep(i, N) {
    rep(j, keta) {
      if (((A[i] >> j) & 1) == 0)
        num_of_zero[j]++;
    }
  }
  reverse(all(num_of_zero));

  ll X = 0;
  ll ans = 0;
  rep(i, keta) {
    ll cand = (ll)1 << (keta - 1 - i);
    if (num_of_zero[i] > N / 2 && X + cand <= K) {
      X += cand;
      ans += cand * num_of_zero[i];
    } else {
      ans += cand * (N - num_of_zero[i]);
    }
  }
  cout << ans << endl;
}