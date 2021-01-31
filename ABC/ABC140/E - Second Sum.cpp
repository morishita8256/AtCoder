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
  ll N;
  cin >> N;
  vector<ll> P(N);
  vector<ll> ind(N);
  rep(i, N) {
    cin >> P[i];
    P[i]--;
    ind[P[i]] = i;
  }

  multiset<ll> s;
  s.insert(-1);
  s.insert(-1);
  s.insert(N);
  s.insert(N);

  ll ans = 0;
  repr(i, N - 1, 0) {
    s.insert(ind[i]);
    auto it = s.lower_bound(ind[i]);
    it--;
    it--;
    ll l2, l1, c, r1, r2;
    l2 = *it;
    it++;
    l1 = *it;
    it++;
    c = *it;
    it++;
    r1 = *it;
    it++;
    r2 = *it;

    ll temp = (c - l1) * (r2 - r1) + (r1 - c) * (l1 - l2);
    ans += (ll)(i + 1) * temp;
  }
  cout << ans << endl;
}