#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
  }
  vector<ll> sum(N);
  sum[0] = A[0];
  repp(i, 1, N - 1) {
    sum[i] = sum[i - 1] + A[i];
  }

  ll ans = LINF;
  repp(c, 1, N - 2) {
    ll l = sum[c];
    auto iter = lower_bound(all(sum), (double)l / 2.0);
    int pos = distance(sum.begin(), iter);
    ll P = sum[pos], Q = l - P;
    if (abs(P - Q) > abs((P - A[pos]) - (Q + A[pos]))) {
      P -= A[pos];
      Q += A[pos];
    }

    ll r = sum[N - 1] - sum[c];
    iter = lower_bound(all(sum), l + (double)r / 2.0);
    pos = distance(sum.begin(), iter);
    ll R = sum[pos] - l, S = r - R;
    if (abs(R - S) > abs((R - A[pos]) - (S + A[pos]))) {
      R -= A[pos];
      S += A[pos];
    }
    chmin(ans, max({P, Q, R, S}) - min({P, Q, R, S}));
  }
  cout << ans << endl;
}