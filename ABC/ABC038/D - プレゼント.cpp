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
  typedef pair<int, int> P;
  vector<P> wh(N);
  rep(i, N) cin >> wh[i].fi >> wh[i].se;

  sort(all(wh));
  vector<int> h;

  rep(i, N) {
    h.pb(wh[i].se);
  }

  int M = h.size();

  vector<int> LIS(N, INF);
  rep(i, M) {
    *lower_bound(all(LIS), h[i]) = h[i];
  }
  auto iter = lower_bound(all(LIS), INF);
  int ans = distance(LIS.begin(), iter);

  cout << ans << endl;
}