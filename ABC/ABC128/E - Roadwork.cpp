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

struct stx {
  ll S, T, X;

  stx(ll s, ll t, ll x) : S(s), T(t), X(x) {}
  bool operator<(const stx& another) const {
    return X < another.X;
  };
};

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<stx> STX;
  rep(i, N) {
    ll S, T, X;
    cin >> S >> T >> X;
    S -= X;
    T -= X;
    STX.pb(stx(S, T, X));
  }

  set<ll> s;
  map<ll, ll> m;
  vector<int> D(Q);
  rep(i, Q) {
    cin >> D[i];
    s.insert(D[i]);
  }

  sort(all(STX));

  rep(i, N) {
    auto iter = s.lower_bound(STX[i].S);
    auto last = s.lower_bound(STX[i].T);
    vector<ll> hit;
    while (iter != last) {
      hit.pb(*iter);
      iter++;
    }
    rep(j, hit.size()) {
      m[hit[j]] = STX[i].X;
      s.erase(hit[j]);
    }
  }

  rep(i, Q) {
    ll ans = m[D[i]] ? m[D[i]] : -1;
    cout << ans << endl;
  }
}