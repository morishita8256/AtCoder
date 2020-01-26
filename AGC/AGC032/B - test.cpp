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
#define debug(var) cout << "[" << #var << "]\n" << var << "\n"
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
      cout << '\n';
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

  int M = N * (N - 1) / 2;
  vector<int> l(M);
  vector<int> r(M);
  int ind = 0;
  rep(i, N) {
    repp(j, i + 1, N - 1) {
      l[ind] = i + 1;
      r[ind] = j + 1;
      ind++;
    }
  }


  /* 2bit */
  rep(b, bit(M)) {
    int num = __builtin_popcount(b);
    vector<int> A(M);
    rep(i, M) {
      if ((b >> i) & 1)
        A[i] = 1;
      else
        A[i] = 0;
    }

    vector<int> sum(N);
    rep(i, M) {
      if (A[i]) {
        sum[l[i] - 1] += r[i];
        sum[r[i] - 1] += l[i];
      }
    }

    set<int> s;
    rep(i, N) {
      s.insert(sum[i]);
    }

    if (len(s) == 1 && num >= N - 1) {
      debug(A);
      debug(l);
      debug(r);
      debug(M);
      debug(num);
    }
  }
}