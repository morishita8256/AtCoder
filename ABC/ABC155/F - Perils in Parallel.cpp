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

struct bomb {
  ll A, B;
  bomb() = default;
  bomb(ll A, ll B) : A(A), B(B) {
  }

  bool operator<(const bomb& another) const {
    return A < another.A;
  };
};

signed main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
  }
  vector<int> L(M), R(M);
  rep(i, M) {
    cin >> L[i] >> R[i];
  }

  vector<bomb> bombs(N);
  rep(i, N) {
    bombs[i].A = A[i];
    bombs[i].B = B[i];
  }
  sort(all(bombs));

  vector<int> b(N);
  rep(i, N) {
    b[i] = bombs[i].B;
  }

  sort(all(A));
  vector<int> l(M), r(M);

  rep(i, M) {
    auto iter = lower_bound(all(A), L[i]);
    int pos = distance(A.begin(), iter);
    l[i] = pos;
  }

  rep(i, M) {
    auto iter = upper_bound(all(A), R[i]);
    int pos = distance(A.begin(), iter);
    r[i] = pos - 1;
  }
}