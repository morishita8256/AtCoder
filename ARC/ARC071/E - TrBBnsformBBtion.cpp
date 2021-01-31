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
  string S;
  cin >> S;
  string T;
  cin >> T;

  int s = len(S), t = len(T);

  vector<int> SA(s + 1), SB(s + 1);
  rep(i, s) {
    SA[i + 1] = SA[i] + (S[i] == 'A');
    SB[i + 1] = SB[i] + (S[i] == 'B');
  }

  vector<int> TA(t + 1), TB(t + 1);
  rep(i, t) {
    TA[i + 1] = TA[i] + (T[i] == 'A');
    TB[i + 1] = TB[i] + (T[i] == 'B');
  }


  int q;
  cin >> q;
  while (q-- > 0) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, c--;
    int ss = (SA[b] - SA[a]) - (SB[b] - SB[a]);
    int tt = (TA[d] - TA[c]) - (TB[d] - TB[c]);

    if ((ss - tt) % 3 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}