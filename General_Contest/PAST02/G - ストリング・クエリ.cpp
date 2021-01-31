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
struct cvector {
  vector<T> vec;
  cvector() : vec(26) {
  }
  cvector(T init) : vec(26, init) {
  }
  T& operator[](char c) {
    return vec[c - 'a'];
  }
};

template <typename T>
ostream& operator<<(ostream& s, const cvector<T>& cvector) {
  s << cvector.vec;
  return s;
}

signed main() {
  int Q;
  cin >> Q;
  typedef pair<int, char> P;
  deque<P> q;

  while (Q-- > 0) {
    int T;
    cin >> T;
    if (T == 1) {
      char C;
      int X;
      cin >> C >> X;
      q.push_back(P(X, C));
    } else if (T == 2) {
      int D;
      cin >> D;

      cvector<int> cnt;
      while (D && !q.empty()) {
        P xc = q.front();
        q.pop_front();

        int x = xc.fi;
        char c = xc.se;

        int erase = min(x, D);
        cnt[c] += erase;
        D -= erase;

        x -= erase;
        if (x > 0)
          q.push_front(P(x, c));
      }

      int ans = 0;
      for (int i = 'a'; i <= 'z'; i++) {
        ans += pow(cnt[i], 2);
      }
      cout << ans << endl;
    }
  }
}