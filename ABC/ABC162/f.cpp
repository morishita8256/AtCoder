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
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  if (N % 2 == 0) {
    vector<int> o(N + 1), e(N + 1), d(N + 1);
    rep(i, N) {
      o[i + 1] = o[i] + (i % 2 == 0 ? A[i] : 0);
      e[i + 1] = e[i] + (i % 2 == 1 ? A[i] : 0);
      d[i + 1] = o[i + 1] - e[i + 1];
    }

    int ans = -LINF;
    rep(i, N + 1) {
      if (i % 2 == 1)
        continue;
      int temp = e[N] + d[i];
      chmax(ans, temp);
    }
    cout << ans << endl;

  } else {
    vector<int> lo(N + 1), le(N + 1), ld(N + 1);
    rep(i, N) {
      lo[i + 1] = lo[i] + (i % 2 == 0 ? A[i] : 0);
      le[i + 1] = le[i] + (i % 2 == 1 ? A[i] : 0);
      ld[i + 1] = lo[i + 1] - le[i + 1];
    }

    vector<int> ro(N + 1), re(N + 1), rd(N + 1);
    repr(i, N, 1) {
      ro[i - 1] = ro[i] + (i % 2 == 1 ? A[i - 1] : 0);
      re[i - 1] = re[i] + (i % 2 == 0 ? A[i - 1] : 0);
      rd[i - 1] = ro[i - 1] - re[i - 1];
    }

    vector<int> lm(N + 1, -LINF);
    rep(i, N) {
      lm[i + 1] = max(lm[i], ld[i]);
    }

    vector<int> rm(N + 1, -LINF);
    repr(i, N, 1) {
      rm[i - 1] = max(rm[i], rd[i]);
    }


    int ans = -LINF;
    rep(i, N + 1) {
      int temp = le[N] + lm[i] + rm[i];
      chmax(ans, temp);
    }

    chmax(ans, lo[N - 1]);
    chmax(ans, ro[2]);
    cout << ans << endl;
  }
}