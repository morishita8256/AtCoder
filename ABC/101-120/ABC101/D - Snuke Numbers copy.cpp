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

int S(int i) {
  int ans = 0;
  while (i) {
    ans += i % 10;
    i /= 10;
  }
  return ans;
}

double g(int i) {
  return (double)i / S(i);
}

signed main() {
  int MAX = 1e+8;
  vector<double> table(MAX + 1);
  repp(i, 1, MAX) {
    table[i] = g(i);
  }

  vector<double> mn(MAX + 1, INF);
  repr(i, MAX - 1, 1) {
    mn[i] = min(mn[i + 1], table[i + 1]);
  }

  vector<int> ans;
  repp(i, 1, 1e+6) {
    if (g(i) <= mn[i])
      ans.pb(i);
  }

  map<int, int> m;
  rep(i, len(ans) - 1) {
    m[ans[i + 1] - ans[i]]++;
  }
  cout << m[10] << ' ' << m[100] << ' ' << m[1000] << ' ' << m[10000] << endl;
}