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

vector<vector<int>> b, c;
vector<vector<char>> a(3, vector<char>(3));
typedef pair<int, int> P;

int dfs(int turn) {
  if (turn == 9) {
    int cho = 0;
    rep(i, 2) {
      rep(j, 3) {
        if (a[i][j] == a[i + 1][j])
          cho += b[i][j];
      }
    }
    rep(i, 3) {
      rep(j, 2) {
        if (a[i][j] == a[i][j + 1])
          cho += c[i][j];
      }
    }
    return cho;
  }

  int mx = 0, mn = INF;
  rep(i, 3) {
    rep(j, 3) {
      if (a[i][j] != '.')
        continue;

      a[i][j] = (turn % 2 ? 'x' : 'o');
      int cho = dfs(turn + 1);
      chmax(mx, cho);
      chmin(mn, cho);
      a[i][j] = '.';
    }
  }

  return (turn % 2 ? mn : mx);
}

signed main() {
  int sum = 0;

  b = vector<vector<int>>(2, vector<int>(3));
  rep(i, 2) {
    rep(j, 3) {
      cin >> b[i][j];
      sum += b[i][j];
    }
  }
  c = vector<vector<int>>(3, vector<int>(2));
  rep(i, 3) {
    rep(j, 2) {
      cin >> c[i][j];
      sum += c[i][j];
    }
  }

  rep(i, 3) {
    rep(j, 3) {
      a[i][j] = '.';
    }
  }

  int cho = dfs(0);
  int na = sum - cho;
  cout << cho << endl;
  cout << na << endl;
}
