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
const double EPS = 1e-8;

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

double find_max(double l, double r, bool f(double)) {
  double c;
  while (abs(r - l) > EPS) {
    c = (r + l) / 2.0;
    if (f(c)) {
      l = c;
    } else {
      r = c;
    }
  }

  return l;
}

int N, M;
vector<double> A, B, C, D;

bool f(double trial) {
  vector<double> surplus;
  rep(i, N) {
    surplus.pb(B[i] - trial * A[i]);
  }

  vector<double> surplus_temp;
  rep(i, M) {
    surplus_temp.pb(D[i] - trial * C[i]);
  }
  sort(all(surplus_temp), greater<double>());
  surplus.pb(surplus_temp[0]);

  sort(all(surplus), greater<double>());

  double sum = 0.0;
  rep(i, 5) {
    sum += surplus[i];
  }

  return sum >= 0;
}


signed main() {
  cin >> N >> M;
  A.assign(N, 0);
  B.assign(N, 0);
  C.assign(M, 0);
  D.assign(M, 0);
  rep(i, N) {
    cin >> A[i] >> B[i];
  }
  rep(i, M) {
    cin >> C[i] >> D[i];
  }

  double ans = find_max(0, 1e+9, f);
  cout << ans << endl;
}