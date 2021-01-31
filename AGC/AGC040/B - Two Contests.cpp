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
typedef pair<ll, ll> P;

int main() {
  int N;
  cin >> N;

  vector<P> LR(N);
  rep(i, N) {
    cin >> LR[i].fi >> LR[i].se;
    LR[i].fi--;
  }
  ll ans = 0;

  sort(all(LR));
  vector<ll> numL(N), mxL(N), mnL(N);
  ll Lmx = 0, Rmn = LINF;
  rep(i, N) {
    chmax(Lmx, LR[i].fi);
    chmin(Rmn, LR[i].se);
    mxL[i] = Lmx;
    mnL[i] = Rmn;
    numL[i] = max(0LL, Rmn - Lmx);
  }

  vector<ll> numR(N), mxR(N), mnR(N);
  Lmx = 0;
  Rmn = LINF;
  repr(i, N - 1, 0) {
    chmax(Lmx, LR[i].fi);
    chmin(Rmn, LR[i].se);
    mxR[i] = Lmx;
    mnR[i] = Rmn;
    numR[i] = max(0LL, Rmn - Lmx);
  }

  rep(i, N - 1) {
    ll temp = numL[i] + numR[i + 1];
    chmax(ans, temp);
  }

  rep(i, N) {
    ll temp = LR[i].se - LR[i].fi;
    if (i == 0) {
      temp += numR[1];
    } else if (i == N - 1) {
      temp += numL[N - 2];
    } else {
      temp +=
          max(0LL, min(mnL[i - 1], mnR[i - 1]) - max(mxR[i + 1], mxL[i + 1]));
    }
    chmax(ans, temp);
  }

  cout << ans << endl;
}