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
#define debug(var) cout << "[" << #var << "]\n" << var << "\n\n"
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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}


signed main() {
  int N, K;
  cin >> N >> K;
  vector<ll> a(N);
  rep(i, N) {
    cin >> a[i];
  }

  vector<ll> sum(N + 1);
  rep(i, N) {
    sum[i + 1] = sum[i] + a[i];
  }

  vector<ll> wa;
  rep(l, N) {
    repp(r, l + 1, N) {
      wa.pb(sum[r] - sum[l]);
    }
  }
  int M = len(wa);

  set<ll> s;
  rep(i, M) {
    s.insert(wa[i]);
  }

  ll ans = 0;
  repr(b, 60, 0) {
    int cnt = 0;
    for (ll elem : s) {
      if ((1LL << b) & elem)
        cnt++;
    }
    if (cnt < K)
      continue;

    ans += (1LL << b);
    rep(i, M) {
      if (!((1LL << b) & wa[i]))
        s.erase(wa[i]);
    }
  }
  cout << ans << "\n";
}