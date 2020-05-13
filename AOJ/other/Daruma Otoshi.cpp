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

int cnt = 10;
vector<int> w;
vector<vector<int>> memo;

int dfs(int l, int r) {
  if (memo[l][r] != -1)
    return memo[l][r];

  int ans = 0;
  if (l == r) {
    ans = 0;
  } else if (l + 1 == r) {
    ans = (abs(w[l] - w[r]) <= 1) * 2;
  } else if (dfs(l + 1, r - 1) == r - l - 1 && abs(w[l] - w[r]) <= 1) {
    ans = r - l + 1;
  } else {
    repp(i, l, r - 1) {
      chmax(ans, dfs(l, i) + dfs(i + 1, r));
    }
  }

  memo[l][r] = ans;
  return ans;
}


signed main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      return 0;

    w = vector<int>(n);
    rep(i, n) {
      cin >> w[i];
    }

    memo = vector<vector<int>>(n, vector<int>(n, -1));

    int ans = dfs(0, n - 1);


    cout << ans << endl;
  }
}