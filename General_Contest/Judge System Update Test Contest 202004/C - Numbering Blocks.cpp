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

int di[2] = {1, 0}, dj[2] = {0, 1};

signed main() {
  vector<int> a(3);
  int N = 0;
  rep(i, 3) {
    cin >> a[i];
    N += a[i];
  }

  typedef pair<int, int> P;
  vector<P> ind2pos(N);

  int ind = 0;
  rep(i, 3) {
    rep(j, a[i]) {
      ind2pos[ind++] = P(i, j);
    }
  }

  vector<vector<int>> table(4, vector<int>(4, 10));

  vector<int> num(N);
  rep(n, N) {
    num[n] = n;
  }

  int ans = 0;
  do {
    rep(n, N) {
      auto pos = ind2pos[n];
      int i = pos.fi, j = pos.se;
      table[i][j] = num[n];
    }

    int ok = true;
    rep(i, 3) {
      rep(j, 3) {
        if (table[i][j] > table[i + 1][j])
          ok = false;
        if (table[i][j] > table[i][j + 1])
          ok = false;
      }
    }
    if (ok)
      ans++;

  } while (next_permutation(all(num)));
  cout << ans << endl;
}