#pragma region head
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
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

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
#pragma endregion

signed main() {
  int N, L;
  cin >> N >> L;
  vector<int> x(N);

  rep(i, N) {
    cin >> x[i];
  }

  int T1, T2, T3;
  cin >> T1 >> T2 >> T3;

  vector<int> cost(L + 1);
  rep(i, N) {
    cost[x[i]] = T3;
  }

  vector<int> dp(L + 10, INF);
  dp[0] = 0;
  repp(i, 0, L - 1) {
    chmin(dp[i + 1], dp[i] + cost[i] + T1);

    if (i + 2 <= L) {
      chmin(dp[i + 2], dp[i] + cost[i] + T1 + T2);
    } else {
      chmin(dp[L], dp[i] + cost[i] + T1 / 2 + T2 / 2);
    }

    if (i + 4 <= L) {
      chmin(dp[i + 4], dp[i] + cost[i] + T1 + 3 * T2);
    } else {
      chmin(dp[L], dp[i] + cost[i] + T1 / 2 + T2 / 2 * (2 * (L - i) - 1));
    }
  }

  int ans = dp[L];
  cout << ans << endl;
}