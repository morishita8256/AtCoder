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
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
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
  int H, W, h, w;
  cin >> H >> W >> h >> w;

  if (H % h + W % w == 0) {
    cout << "No\n";
    return 0;
  }

  bool T = false;
  if (W % w == 0) {
    T = true;
    swap(H, W), swap(h, w);
  }

  vector<int> s(W + 1);
  s[W] = 1;
  for (int i = 0; i + w <= W; i += w) {
    s[i + w] = s[i] - 1;
  }

  for (int i = W; i - w >= 0; i -= w) {
    s[i - w] = s[i] + 1;
  }

  for (int i = 0; i + w <= W; i++) {
    if (s[i + w] >= s[i])
      s[i + w] = s[i] - 1;
  }

  vector<int> a(W);
  rep(i, W) {
    a[i] = s[i + 1] - s[i];
  }

  vector<vector<int>> ans(H, vector<int>(W));
  rep(i, H) {
    rep(j, W) {
      ans[i][j] = a[j];
    }
  }

  if (T) {
    auto ans_cp = ans;
    ans = vector<vector<int>>(W, vector<int>(H));
    rep(i, H) {
      rep(j, W) {
        ans[j][i] = ans_cp[i][j];
      }
    }
  }

  cout << "Yes\n";
  cout << ans << endl;
}