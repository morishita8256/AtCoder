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

  int min_all = INF, min_even = INF;
  int cnt_all = 0, cnt_even = 0;

  vector<int> C(N);
  rep(i, N) {
    cin >> C[i];

    chmin(min_all, C[i]);

    if (i % 2 == 0)
      chmin(min_even, C[i]);
  }


  int Q;
  cin >> Q;

  int ans = 0;
  while (Q-- > 0) {
    int q;
    cin >> q;

    if (q == 1) {
      int x, a;
      cin >> x >> a;
      x--;

      int temp = C[x] - cnt_all - cnt_even * (x % 2 == 0);
      if (temp >= a) {
        C[x] -= a;
        ans += a;

        chmin(min_all, C[x]);
        if (x % 2 == 0)
          chmin(min_even, C[x]);
      }
    } else if (q == 2) {
      int a;
      cin >> a;

      if (min_even >= a) {
        cnt_even += a;
        min_even -= a;

        chmin(min_all, min_even);

        int num_even = (N + 1) / 2;
        ans += a * num_even;
      }
    } else {
      int a;
      cin >> a;

      if (min_all >= a) {
        min_all -= a;
        cnt_all += a;

        min_even -= a;

        ans += a * N;
      }
    }
  }

  cout << ans << endl;
}