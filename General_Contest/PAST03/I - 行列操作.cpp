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

signed main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> I(N), J(N);
  rep(k, N) {
    I[k] = k, J[k] = k;
  }

  int T = 0;
  rep(_, Q) {
    int q;
    cin >> q;
    if (q == 1) {
      int A, B;
      cin >> A >> B;
      A--, B--;
      if (T % 2 == 0)
        swap(I[A], I[B]);
      else
        swap(J[A], J[B]);
    } else if (q == 2) {
      int A, B;
      cin >> A >> B;
      A--, B--;
      if (T % 2 == 0)
        swap(J[A], J[B]);
      else
        swap(I[A], I[B]);
    } else if (q == 3) {
      T += 1;
    } else {
      int A, B;
      cin >> A >> B;
      A--, B--;
      if (T % 2)
        swap(A, B);
      int i = I[A], j = J[B];
      int ans = N * i + j;
      cout << ans << endl;
    }
  }
}