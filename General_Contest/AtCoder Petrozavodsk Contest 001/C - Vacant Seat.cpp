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
  int N;
  cin >> N;

  int l = 0, r = N;

  cout << 0 << endl;
  fflush(stdout);
  string s;
  cin >> s;
  if (s == "Vacant")
    return 0;


  string L = s, R = s;

  while (r - l > 1) {
    int m = (r + l) / 2;
    cout << m << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s == "Vacant")
      return 0;

    int lm = (m - l - 1) % 2, mr = (r - m - 1) % 2;
    if (lm ^ (L == s))
      r = m;
    else
      l = m;
  }

  cout << l << endl;
  fflush(stdout);
  cin >> s;
  if (s == "Vacant")
    return 0;

  cout << r << endl;
  fflush(stdout);
  cin >> s;
  if (s == "Vacant")
    return 0;
}