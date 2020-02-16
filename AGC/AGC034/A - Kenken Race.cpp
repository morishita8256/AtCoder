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
typedef long long ll;
const int INF = 1001001001;
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

bool ok(string& S, int l, int r) {
  repp(i, l, r - 1) {
    if (S[i] == S[i + 1] && S[i + 1] == '#')
      return false;
  }
  return true;
}

bool triple(string& S, int l, int r) {
  repp(i, l - 1, r - 1) {
    if (S[i] == S[i + 1] && S[i + 1] == S[i + 2] && S[i] == '.')
      return true;
  }
  return false;
}

signed main() {
  int N;
  cin >> N;
  int A, B;
  cin >> A >> B;
  A--, B--;
  int C, D;
  cin >> C >> D;
  C--, D--;
  string S;
  cin >> S;

  if (C < D) {
    if (ok(S, B, D) && ok(S, A, C))
      cout << "Yes\n";
    else
      cout << "No\n";
  } else {
    if (ok(S, B, D) && ok(S, A, C) && triple(S, B, D))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}