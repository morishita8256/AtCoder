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
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<ll> s(A + 2);
  repp(i, 1, A) cin >> s[i];
  vector<ll> t(B + 2);
  repp(i, 1, B) cin >> t[i];
  vector<ll> x(Q + 1);
  repp(i, 1, Q) cin >> x[i];

  s[0] = t[0] = -LINF / 2;
  s[A + 1] = t[B + 1] = LINF / 2;

  repp(i, 1, Q) {
    vector<ll> ss(2);
    auto itr = lower_bound(all(s), x[i]);
    ss[0] = *itr;
    ss[1] = *(itr - 1);

    vector<ll> tt(2);
    itr = lower_bound(all(t), x[i]);
    tt[0] = *itr;
    tt[1] = *(itr - 1);

    ll ans = LINF;
    rep(sss, 2) {
      rep(ttt, 2) {
        ll ds = ss[sss];
        ll dt = tt[ttt];

        ll temp = abs(ds - dt) + min(abs(x[i] - ds), abs(x[i] - dt));
        chmin(ans, temp);
      }
    }
    cout << ans << endl;
  }
}