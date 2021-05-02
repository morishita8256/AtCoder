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
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
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

signed main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N), B(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
    B[i]--;
  }
  vector<int> C(Q), D(Q);
  rep(i, Q) {
    cin >> C[i] >> D[i];
    C[i]--, D[i]--;
  }

  int M = 200000;
  vector<multiset<int>> K(M);
  rep(i, N) {
    K[B[i]].insert(A[i]);
  }

  multiset<int> T;
  rep(i, M) {
    if (!K[i].empty())
      T.insert(*K[i].rbegin());
  }

  rep(i, Q) {
    int from = B[C[i]], to = D[i];
    int r = A[C[i]];

    B[C[i]] = to;

    // from
    T.erase(T.find(*K[from].rbegin()));
    K[from].erase(K[from].find(r));
    if (!K[from].empty())
      T.insert(*K[from].rbegin());

    // to
    if (!K[to].empty())
      T.erase(T.find(*K[to].rbegin()));
    K[to].insert(r);
    T.insert(*K[to].rbegin());

    int ans = *T.begin();
    cout << ans << endl;
  }
}