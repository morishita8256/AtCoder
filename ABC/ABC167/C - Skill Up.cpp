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
  int N, M, X;
  cin >> N >> M >> X;

  vector<int> C(N);
  vector<vector<int>> A(N, vector<int>(M));
  rep(i, N) {
    cin >> C[i];
    rep(j, M) {
      cin >> A[i][j];
    }
  }

  int ans = INF;
  rep(b, bit(N)) {
    int cost = 0;
    vector<int> x(M);
    rep(i, N) {
      if ((b >> i) & 1) {
        cost += C[i];
        rep(j, M) {
          x[j] += A[i][j];
        }
      }
    }
    bool ok = true;
    rep(j, M) {
      if (x[j] < X)
        ok = false;
    }

    if (ok)
      chmin(ans, cost);
  }

  if (ans == INF)
    ans = -1;
  cout << ans << endl;
}