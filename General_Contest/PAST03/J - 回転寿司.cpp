#pragma region head
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
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

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
#pragma endregion

// 引数は(ok, ng)
#pragma region bin_search
bool f(ll trial);

template <class T>
T bin_search(T ok, T ng) {
  T c;
  while (abs(ok - ng) > 1) {
    c = (ok + ng) / 2;
    if (f(c)) {
      ok = c;
    } else {
      ng = c;
    }
  }

  return ok;
}
#pragma endregion

int A;
vector<int> mx;

bool f(int trial) {
  return mx[trial] < A;
}


signed main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  rep(i, M) {
    cin >> a[i];
  }
  mx = vector<int>(N + 1);
  rep(i, M) {
    A = a[i];
    int ind = bin_search(N, -1ll);
    if (ind == N) {
      cout << -1 << '\n';
    } else {
      cout << (ind + 1) << endl;
      mx[ind] = A;
    }
  }
}