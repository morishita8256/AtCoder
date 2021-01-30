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

int ff(int n) {
  int res = 0;
  while (n != 0) {
    res++;
    n %= __builtin_popcount(n);
  }
  return res;
}

signed main() {
  int N;
  cin >> N;
  string X;
  cin >> X;

  int B = 0;
  for (char c : X) {
    B += c == '1';
  }

  int Bp = B + 1, Bm = B - 1;

  if (Bm == 0) {
    vector<int> R(N);
    int t = 1;
    rep(i, N) {
      t %= 2;
      R[i] = t;
      t *= 2;
    }
    reverse(all(R));

    int ind = -1;
    rep(i, N) {
      if (X[i] == '1') {
        ind = i;
        break;
      }
    }

    rep(i, N) {
      if (X[i] == '1')
        cout << 0 << endl;
      else {
        int temp = R[ind] + R[i];
        temp %= 2;
        int ans = ff(temp) + 1;
        cout << ans << endl;
      }
    }

    return 0;
  }

  int Sp = 0, Sm = 0;
  for (char c : X) {
    Sp = Sp * 2 + c - '0';
    Sp %= Bp;
    Sm = Sm * 2 + c - '0';
    Sm %= Bm;
  }

  vector<int> Rp(N), Rm(N);
  int tp = 1, tm = 1;
  rep(i, N) {
    tp %= Bp;
    Rp[i] = tp;
    tp *= 2;
    tm %= Bm;
    Rm[i] = tm;
    tm *= 2;
  }
  reverse(all(Rp));
  reverse(all(Rm));

  rep(i, N) {
    int n;
    if (X[i] == '1') {  // m
      n = Sm - Rm[i];
      n = (n + Bm) % Bm;
    } else {
      n = Sp + Rp[i];
      n %= Bp;
    }
    int ans = ff(n) + 1;
    cout << ans << endl;
  }
}