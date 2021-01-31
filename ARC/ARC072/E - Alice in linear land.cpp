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
  int N, D;
  cin >> N >> D;
  vector<int> d(N);
  rep(i, N) {
    cin >> d[i];
  }
  int Q;
  cin >> Q;
  vector<int> q(Q);
  rep(i, Q) {
    cin >> q[i];
    q[i]--;
  }


  int temp = D;
  vector<int> A(N);
  rep(i, N) {
    A[i] = temp;
    temp = min(temp, abs(temp - d[i]));
  }

  if (temp) {
    while (Q-- > 0)
      cout << "YES\n";
    return 0;
  }

  vector<int> B(N);
  temp = 1;
  repr(i, N - 1, 0) {
    B[i] = temp;
    temp = (temp * 2 <= d[i]) ? temp : temp + d[i];
  }

  rep(i, Q) {
    if (B[q[i]] <= A[q[i]])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}