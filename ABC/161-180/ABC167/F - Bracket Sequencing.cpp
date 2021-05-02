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

template <typename T>
struct SegmentTree {
  using F = function<T(T, T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f, T ti) : f(f), ti(ti) {
  }

  void init(int n_) {
    n = 1;
    while (n < n_)
      n <<= 1;
    dat.assign(n << 1, ti);
  }

  void build(const vector<T>& v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++)
      dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }

  void update(int k, T x) {
    dat[k += n] = x;
    while (k >>= 1)
      dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
  }

  // [a, b)
  T query(int a, int b) {
    T vl = ti, vr = ti;
    for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        vl = f(vl, dat[l++]);
      if (r & 1)
        vr = f(dat[--r], vr);
    }
    return f(vl, vr);
  }
};

struct LR {
  ll L, R, D;
  LR() = default;
  LR(ll L, ll R) : L(L), R(R) {
    D = L - R;
  }

  bool operator<(const LR& another) const {
    return R < another.R;
  }
  bool operator>(const LR& another) const {
    return L > another.L;
  }
};

signed main() {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, N) {
    cin >> S[i];
  }

  vector<int> L(N), R(N), D(N);
  vector<string> T;
  rep(i, N) {
    int left = 0;
    int right = 0;
    rep(j, len(S[i])) {
      (S[i][j] == '(' ? left : right)++;
      if (S[i][j] == ')' && left > 0) {
        left--, right--;
      }
    }
    L[i] = left, R[i] = right;
    D[i] = L[i] - R[i];
  }


  vector<LR> LRs(N);
  rep(i, N) {
    LRs[i].L = L[i];
    LRs[i].R = R[i];
    LRs[i].D = L[i] - R[i];
  }
  sort(all(LRs));

  vector<LR> Asc, Dsc;
  rep(i, N) {
    (LRs[i].D > 0 ? Asc : Dsc).pb(LRs[i]);
  }

  sort(all(Asc));
  sort(all(Dsc), greater<>());


  int H = 0;
  for (auto LR : Asc) {
    H -= LR.R;
    if (H < 0) {
      cout << "No\n";
      return 0;
    }
    H += LR.L;
  }

  for (auto LR : Dsc) {
    H -= LR.R;
    if (H < 0) {
      cout << "No\n";
      return 0;
    }
    H += LR.L;
  }

  if (H == 0)
    cout << "Yes\n";
  else
    cout << "No\n";
}