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
  vector<string> s(N);
  rep(i, N) {
    cin >> s[i];
  }

  int ans = 0;

  int B__ = 0;
  int __A = 0;
  int B_A = 0;
  rep(i, N) {
    int M = len(s[i]);
    rep(j, M - 1) {
      if (s[i][j] == 'A' && s[i][j + 1] == 'B')
        ans++;
    }

    bool B = s[i][0] == 'B';
    bool A = s[i][M - 1] == 'A';

    if (A && B)
      B_A++;
    else if (A)
      __A++;
    else if (B)
      B__++;
  }

  if (B_A) {
    ans += B_A - 1;
    if (__A) {
      ans++;
      __A--;
    }
    if (B__) {
      ans++;
      B__--;
    }
  }

  ans += min(__A, B__);
  cout << ans << endl;
}