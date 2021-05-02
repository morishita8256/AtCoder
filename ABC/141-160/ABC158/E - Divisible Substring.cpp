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
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
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
  int N, P;
  cin >> N >> P;
  string S;
  cin >> S;

  vector<int> A(N);
  rep(i, N) {
    A[i] = S[i] - '0';
  }

  if (P == 2 || P == 5) {
    int ans = 0;
    rep(i, N) {
      if (A[i] % P == 0)
        ans += (i + 1);
    }
    cout << ans << endl;
    return 0;
  }

  vector<int> sum(N + 1);

  reverse(all(A));

  int ten = 1;
  rep(i, N) {
    sum[i + 1] = sum[i] + A[i] * ten;
    sum[i + 1] %= P;
    ten *= 10;
    ten %= P;
  }

  vector<int> cnt(10001);
  rep(i, N + 1) {
    cnt[sum[i]]++;
  }

  int ans = 0;
  rep(i, 10001) {
    ans += cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << ans << endl;
}