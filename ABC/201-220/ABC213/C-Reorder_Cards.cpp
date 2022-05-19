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

template <typename T>
struct Compress {
  vector<T> xs;
  Compress() = default;
  Compress(const vector<T>& vs) {
    add(vs);
  }
  Compress(const initializer_list<vector<T>>& vs) {
    for (auto& p : vs) add(p);
  }
  void add(const vector<T>& vs) {
    copy(begin(vs), end(vs), back_inserter(xs));
  }
  void add(const T& x) {
    xs.emplace_back(x);
  }
  void build() {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
  }
  vector<int> get(const vector<T>& vs) const {
    vector<int> ret;
    transform(begin(vs), end(vs), back_inserter(ret), [&](const T& x) {
      return lower_bound(begin(xs), end(xs), x) - begin(xs);
    });
    return ret;
  }
  int get(const T& x) const {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }
  const T& operator[](int k) const {
    return xs[k];
  }
};

signed main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> A(N), B(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }

  Compress<int> AA(A);
  AA.build();
  auto AAA = AA.get(A);

  Compress<int> BB(B);
  BB.build();
  auto BBB = BB.get(B);

  rep(i, N) {
    cout << (AAA[i] + 1) << ' ' << (BBB[i] + 1) << endl;
  }
}