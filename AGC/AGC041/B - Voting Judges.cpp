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

template <class T>
T find_max(T l, T r, bool f(T)) {
  T c;
  while (r - l > 1) {
    c = (r + l) / 2;
    if (f(c)) {
      l = c;
    } else {
      r = c;
    }
  }

  return l;
}

int N, M;
int V, P;
vector<int> A;


bool f(ll i) {
  if (i + 1 <= P)
    return true;

  vector<int> temp(i + 1 - P);
  rep(j, i + 1 - P) {
    temp[j] = A[i - 1 - j] - A[i];
  }

  int sum = 0, mx = 0;
  for (auto elem : temp) {
    sum += elem;
    chmax(mx, elem);
  }

  return (mx <= M && sum <= M * V);
}

signed main() {
  cin >> N >> M;
  cin >> V >> P;

  V = N - V;

  A = vector<int>(N);

  rep(i, N) {
    cin >> A[i];
  }
  sort(all(A), greater<int>());

  int ans = find_max(0LL, N, f) + 1;
  cout << ans << endl;
}