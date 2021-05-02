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
  vector<ll> a(N);
  rep(i, N) cin >> a[i];
  vector<ll> b(N);
  rep(i, N) cin >> b[i];

  ll ans = 0;
  rep(i, 30) {
    vector<ll> bb(N);
    rep(j, N) {
      bb[j] = b[j] % bit(i + 1);
    }
    sort(all(bb));

    ll cnt = 0;
    rep(k, N) {
      ll A = a[k] % bit(i + 1);
      if (A <= bit(i)) {
        auto l = lower_bound(all(bb), bit(i) - A);
        auto r = lower_bound(all(bb), bit(i + 1) - A);
        cnt += r - l;
      } else {
        auto l = lower_bound(all(bb), bit(i + 1) + bit(i) - A);
        auto r = lower_bound(all(bb), bit(i + 1) - A);
        cnt += l - bb.begin();
        cnt += bb.end() - r;
      }
    }

    if (cnt & 1)
      ans += bit(i);
  }
  cout << ans << endl;
}