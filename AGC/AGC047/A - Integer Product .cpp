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

struct B {
  ll num, two, five;
  B() = default;
  B(ll num, ll two, ll five) : num(num), two(two), five(five) {
  }

  bool operator<(const B& another) const {
    return two < another.two;
  };
};


signed main() {
  int N;
  cin >> N;
  vector<double> A(N);
  vector<B> Bs(N);

  int T = 18, F = 18;
  vector<vector<int>> table(T + 1, vector<int>(F + 1));

  rep(i, N) {
    cin >> A[i];
    Bs[i].num = A[i] * 1000000000 + 0.5;

    int b = Bs[i].num;
    while (b % 2 == 0) {
      b /= 2;
      Bs[i].two++;
      if (Bs[i].two == 18)
        break;
    }

    while (b % 5 == 0) {
      b /= 5;
      Bs[i].five++;
      if (Bs[i].five == 18)
        break;
    }

    table[Bs[i].two][Bs[i].five]++;
  }

  int ans = 0;
  rep(t, T + 1) {
    rep(f, F + 1) {
      repp(tt, max(0ll, 18 - t), T) {
        repp(ff, max(0ll, 18 - f), F) {
          if (t == tt && f == ff)
            ans += table[t][f] * (table[tt][ff] - 1);
          else
            ans += table[t][f] * table[tt][ff];
        }
      }
    }
  }

  ans /= 2;
  cout << ans << endl;
}