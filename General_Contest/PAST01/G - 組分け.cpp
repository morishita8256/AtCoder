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

int bit3(int n) {
  int temp = 1;
  rep(i, n) {
    temp *= 3;
  }
  return temp;
}

int shift3(int b, int n) {
  rep(i, n) {
    b /= 3;
  }
  return b;
}

signed main() {
  int N;
  cin >> N;

  vector<vector<int>> A;

  repp(i, 0, N - 2) {
    repp(j, i + 1, N - 1) {
      int a;
      cin >> a;
      A.pb(vector<int>{i, j, a});
    }
  }

  int ans = -INF;
  vector<int> group(N);
  rep(b, bit3(N)) {
    rep(i, N) {
      group[i] = shift3(b, i) % 3;  // 0 or 1 or 2
    }

    int temp = 0;
    for (auto v : A) {
      temp += v[2] * (group[v[0]] == group[v[1]]);
    }
    chmax(ans, temp);
  }
  cout << ans << endl;
}