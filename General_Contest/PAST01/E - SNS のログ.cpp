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
  int N, Q;
  cin >> N >> Q;


  vector<vector<char>> ans(N, vector<char>(N, 'N'));

  while (Q-- > 0) {
    int q;
    cin >> q;

    if (q == 1) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      ans[a][b] = 'Y';
    } else if (q == 2) {
      int a;
      cin >> a;
      a--;
      rep(i, N) {
        if (ans[i][a] == 'Y')
          ans[a][i] = 'Y';
      }
    } else {
      int a;
      cin >> a;
      a--;

      set<int> s;
      rep(j, N) {
        if (ans[a][j] == 'Y') {
          rep(jj, N) {
            if (ans[j][jj] == 'Y')
              s.insert(jj);
          }
        }
      }
      for (int b : s)
        ans[a][b] = 'Y';
    }
  }

  rep(i, N) {
    ans[i][i] = 'N';
  }

  cout << ans << endl;
}