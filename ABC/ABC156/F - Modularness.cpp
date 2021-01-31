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

signed main() {
  int k, q;
  cin >> k >> q;
  vector<int> d(k);
  rep(i, k) {
    cin >> d[i];
  }
  vector<int> n(q), x(q), m(q);
  rep(i, q) {
    cin >> n[i] >> x[i] >> m[i];
    x[i] %= m[i];
  }

  rep(i, q) {
    vector<int> d_mod(k);
    int d_sum = 0;
    int mod0 = 0;
    rep(j, k) {
      d_mod[j] = d[j] % m[i];
      d_sum += d_mod[j];
      mod0 += (d_mod[j] == 0);
    }


    int plus = n[i] - 1;

    int sum = x[i];
    int nochange = 0;

    sum += plus / k * d_sum;
    nochange += plus / k * mod0;

    rep(j, plus % k) {
      sum += d_mod[j];
      nochange += (d_mod[j] == 0);
    }

    int exceed = sum / m[i];

    int ans = n[i] - 1 - exceed - nochange;
    cout << ans << endl;
  }
}