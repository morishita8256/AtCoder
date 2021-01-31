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

int A, B, C, D;
map<int, int> memo;

int rec(int X) {
  if (X == 0)
    return 0;
  if (X == 1)
    return D;

  if (memo.find(X) != memo.end())
    return memo[X];

  int l2 = X / 2 * 2, r2 = (X + 1) / 2 * 2;
  int l3 = X / 3 * 3, r3 = (X + 2) / 3 * 3;
  int l5 = X / 5 * 5, r5 = (X + 4) / 5 * 5;

  int res = INF;
  if (res / D > X)
    res = X * D;
  chmin(res, llabs(l2 - X) * D + A + rec(l2 / 2));
  chmin(res, llabs(r2 - X) * D + A + rec(r2 / 2));
  chmin(res, llabs(l3 - X) * D + B + rec(l3 / 3));
  chmin(res, llabs(r3 - X) * D + B + rec(r3 / 3));
  chmin(res, llabs(l5 - X) * D + C + rec(l5 / 5));
  chmin(res, llabs(r5 - X) * D + C + rec(r5 / 5));
  return memo[X] = res;
}

signed main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    int N;
    cin >> N;
    cin >> A >> B >> C >> D;

    memo.clear();
    int ans = rec(N);
    cout << ans << endl;
  }
}