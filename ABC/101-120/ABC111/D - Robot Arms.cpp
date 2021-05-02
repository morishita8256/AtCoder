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

char f(char u, char v) {
  if (u == 'm' && v == 'm')
    return 'L';
  else if (u == 'm')
    return 'D';
  else if (v == 'm')
    return 'U';
  else
    return 'R';
}

signed main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  rep(i, N) {
    cin >> X[i] >> Y[i];
  }

  int parity = (X[0] + Y[0] + 10000000000) % 2;
  rep(i, N) {
    if ((X[i] + Y[i] + 10000000000) % 2 != parity) {
      cout << -1 << '\n';
      return 0;
    }
  }

  bool even = (parity == 0);
  rep(i, N) {
    X[i] -= even;
  }

  int keta = 32;
  int m = keta + even;
  vector<int> d(keta);
  int bin = 1;
  rep(i, keta) {
    d[i] = bin;
    bin *= 2;
  }

  reverse(all(d));
  if (even)
    d.pb(1);

  cout << m << endl;
  cout << d << endl;


  rep(i, N) {
    int U = X[i] + Y[i];
    int V = X[i] - Y[i];

    int u = 0, v = 0;
    rep(j, keta) {
      int num = u - d[j], nup = u + d[j];
      char uc;
      if (abs(num - U) < abs(nup - U)) {
        uc = 'm';
        u = num;
      } else {
        uc = 'p';
        u = nup;
      }

      int nvm = v - d[j], nvp = v + d[j];
      char vc;
      if (abs(nvm - V) < abs(nvp - V)) {
        vc = 'm';
        v = nvm;
      } else {
        vc = 'p';
        v = nvp;
      }

      cout << f(uc, vc);
    }
    if (even)
      cout << 'R';
    cout << '\n';
  }
}