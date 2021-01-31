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
      cout << '\n';
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
  vector<vector<char>> S(N, vector<char>(N));
  rep(i, N) {
    rep(j, N) {
      cin >> S[i][j];
    }
  }

  vector<vector<char>> SS(2 * N, vector<char>(2 * N));
  rep(i, N) {
    rep(j, N) {
      SS[i][j] = S[i][j];
      SS[i + N][j] = S[i][j];
      SS[i][j + N] = S[i][j];
      SS[i + N][j + N] = S[i][j];
    }
  }

  int ans = 0;
  rep(i, N) {
    int j = 0;
    bool ok = true;
    rep(ii, N) {
      rep(jj, N) {
        if (SS[i + ii][j + jj] != SS[i + jj][j + ii])
          ok = false;
      }
    }
    if (ok)
      ans++;
  }
  ans *= N;
  cout << ans << endl;
}