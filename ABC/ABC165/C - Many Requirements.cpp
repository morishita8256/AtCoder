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

int N, M, Q;
vector<int> a, b, c, d;
vector<int> A;
int ans = 0;

void dfs(int i) {
  if (i == N) {
    int temp = 0;
    rep(q, Q) {
      if (A[b[q]] - A[a[q]] == c[q])
        temp += d[q];
    }
    chmax(ans, temp);
    return;
  }

  int mx = (i == 0 ? 1 : A[i - 1]);
  repp(j, mx, M) {
    A[i] = j;
    dfs(i + 1);
  }
}


signed main() {
  cin >> N >> M >> Q;
  a.assign(Q, 0);
  b.assign(Q, 0);
  c.assign(Q, 0);
  d.assign(Q, 0);
  rep(i, Q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--, b[i]--;
  }

  A.assign(N, 0);

  dfs(0);

  cout << ans << endl;
}