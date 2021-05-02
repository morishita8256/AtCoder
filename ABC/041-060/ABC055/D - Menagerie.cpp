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
  int N;
  cin >> N;
  string s;
  cin >> s;

  map<char, char> inv = {{'S', 'W'}, {'W', 'S'}};

  string ans;
  vector<string> heads = {"SS", "SW", "WS", "WW"};
  for (auto head : heads) {
    ans = head;
    repp(i, 1, N - 2) {
      char p = ans[len(ans) - 2];
      char c = ans[len(ans) - 1];
      if (c == 'S' ^ s[i] == 'x') {
        ans.pb(p);
      } else {
        ans.pb(inv[p]);
      }
    }

    bool ok = true;
    if (ans[0] == 'S' ^ s[0] == 'x') {
      if (ans[1] != ans[N - 1])
        ok = false;
    } else {
      if (ans[1] == ans[N - 1])
        ok = false;
    }

    if (ans[N - 1] == 'S' ^ s[N - 1] == 'x') {
      if (ans[0] != ans[N - 2])
        ok = false;
    } else {
      if (ans[0] == ans[N - 2])
        ok = false;
    }

    if (ok) {
      cout << ans << endl;
      return 0;
    }
  }
  cout << -1 << '\n';
}