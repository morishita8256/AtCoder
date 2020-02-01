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
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      cout << '\n';
  }
  return s;
}

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

// __attribute__((constructor)) void initial() {
//   cin.tie(nullptr);
//   ios::sync_with_stdio(false);
//   cout << fixed << setprecision(15);
// }

signed main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  ll Q;
  cin >> Q;
  vector<ll> k(Q);
  rep(i, Q) {
    cin >> k[i];
  }

  rep(q, Q) {
    ll D = 0, M = 0, DM = 0;
    ll r = 0;
    ll ans = 0;
    rep(l, N - k[q] + 1) {
      while (r < N && r - l < k[q]) {
        if (S[r] == 'D')
          D++;
        else if (S[r] == 'M') {
          M++;
          DM += D;
        } else if (S[r] == 'C')
          ans += DM;
        r++;
      }

      if (S[l] == 'D') {
        D--;
        DM -= M;
      } else if (S[l] == 'M')
        M--;
    }
    cout << ans << endl;
  }
}