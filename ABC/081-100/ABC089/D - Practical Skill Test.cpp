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
  int H, W, D;
  cin >> H >> W >> D;
  vector<vector<int>> A(H, vector<int>(W));
  typedef pair<ll, ll> P;
  vector<P> loc(H * W);

  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
      A[i][j]--;
      loc[A[i][j]] = make_pair((ll)i, (ll)j);
    }
  }
  int Q;
  cin >> Q;
  vector<ll> L(Q), R(Q);
  rep(i, Q) {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
  }

  vector<ll> sum(H * W);
  repp(i, D, H * W - 1) {
    P& prev = loc[i - D];
    P& now = loc[i];

    ll dist = abs(now.fi - prev.fi) + abs(now.se - prev.se);
    sum[i] = sum[i - D] + dist;
  }

  rep(i, Q) {
    cout << sum[R[i]] - sum[L[i]] << endl;
  }
}