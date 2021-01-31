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
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  rep(i, N) {
    cin >> a[i];
  }

  vector<vector<bool>> L(N + 1, vector<bool>(K + 1, false));
  L[0][0] = true;
  rep(i, N) {
    rep(j, K + 1) {
      if (!L[i][j])
        continue;

      L[i + 1][j] = true;
      if (j + a[i] <= K)
        L[i + 1][j + a[i]] = true;
    }
  }

  vector<vector<bool>> R(N + 1, vector<bool>(K + 1, false));
  R[N][0] = true;
  repr(i, N, 1) {
    rep(j, K + 1) {
      if (!R[i][j])
        continue;

      R[i - 1][j] = true;
      if (j + a[i - 1] <= K)
        R[i - 1][j + a[i - 1]] = true;
    }
  }

  int ans = 0;
  rep(i, N) {
    vector<int> l, r;
    repp(j, 0, K) {
      if (L[i][j])
        l.pb(j);
      if (R[i + 1][j])
        r.pb(j);
    }

    bool need = false;
    for (int ll : l) {
      auto itl = lower_bound(all(r), K - a[i] - ll);
      auto itr = lower_bound(all(r), K - ll);
      if (itl != itr) {
        need = true;
        break;
      }
    }

    if (!need)
      ans++;
  }
  cout << ans << endl;
}