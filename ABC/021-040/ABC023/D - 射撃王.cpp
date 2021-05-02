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

template <class T>
T find_min(T l, T r, bool f(T)) {
  T c;
  while (r - l > 1) {
    c = (r + l) / 2;
    if (f(c)) {
      r = c;
    } else {
      l = c;
    }
  }

  return r;
}

int N;
vector<int> H, S;
bool f(int trial) {
  vector<int> time(N);
  rep(i, N) {
    if (trial - H[i] < 0)
      return false;
    time[i] = (trial - H[i]) / S[i];
  }
  sort(all(time));

  rep(i, N) {
    if (time[i] < i)
      return false;
  }
  return true;
}

signed main() {
  cin >> N;
  H = vector<int>(N);
  S = vector<int>(N);
  rep(i, N) {
    cin >> H[i] >> S[i];
  }

  int ans = find_min(0ll, INF, f);
  cout << ans << endl;
}