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
      s << '\n';
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
  ll N, M;
  cin >> N >> M;
  vector<ll> X(N);
  rep(i, N) {
    cin >> X[i];
  }

  map<int, int> m;
  vector<ll> cnt(M), cnt_pair(M);
  rep(i, N) {
    cnt[X[i] % M]++;
    m[X[i]]++;
    if (m[X[i]] % 2 == 0)
      cnt_pair[X[i] % M]++;
  }


  ll ans = 0;
  repp(i, 1, (M - 1) / 2) {
    int l = i, s = M - i;
    if (cnt[l] < cnt[s])
      swap(l, s);
    ans += cnt[s];
    ans += min(cnt_pair[l], (cnt[l] - cnt[s]) / 2);
  }

  ans += cnt[0] / 2;
  if (M % 2 == 0)
    ans += cnt[M / 2] / 2;

  cout << ans << endl;
}