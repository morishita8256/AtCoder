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

int sign(int x) {
  if (x == 0)
    return 0;
  else
    return x / abs(x);
}

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> sum(n);
  rep(i, n) {
    cin >> a[i];
    sum[i] = (i == 0 ? 0 : sum[i - 1]) + a[i];
  }

  int ans = INF;

  for (int sign_raw = -1; sign_raw <= 1; sign_raw += 2) {
    int sg = sign_raw, temp = 0, cum = 0;
    rep(i, n) {
      int s = sum[i] + cum;
      if (sg == 1) {
        if (sign(s) != 1) {
          int diff = 1 - s;
          temp += diff;
          cum += diff;
        }
      } else {
        if (sign(s) != -1) {
          int diff = s - (-1);
          temp += diff;
          cum -= diff;
        }
      }
      sg *= -1;
    }
    chmin(ans, temp);
  }

  cout << ans << endl;
}