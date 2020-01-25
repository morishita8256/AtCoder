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
#define debug(var) cout << "[" << #var << "]\n" << var << "\n\n"
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

vector<int> di = {0, -1, 0, 1};
vector<int> dj = {1, 0, -1, 0};


signed main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> b(N, vector<char>(M));
  rep(i, N) {
    rep(j, M) {
      cin >> b[i][j];
    }
  }


  vector<vector<int>> a(N, vector<int>(M));
  repp(i, 1, N - 2) {
    repp(j, 1, M - 2) {
      int temp = 10;
      rep(d, 4) {
        chmin(temp, b[i + di[d]][j + dj[d]] - '0');
      }
      a[i][j] = temp;
      rep(d, 4) {
        b[i + di[d]][j + dj[d]] -= temp;
      }
    }
  }

  cout << a << "\n";
}