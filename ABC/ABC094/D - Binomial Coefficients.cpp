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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  ll x = a[n - 1];
  ll y;

  double th = (double)x / 2.0;
  auto iter = lower_bound(all(a), th);
  int pos = distance(a.begin(), iter);
  ll cand1 = *iter;
  ll cand2 = (pos > 0) ? (*(iter - 1)) : -1;
  if (cand1 - th < th - cand2) {
    y = cand1;
  } else {
    y = cand2;
  }

  cout << x << ' ' << y << endl;
}