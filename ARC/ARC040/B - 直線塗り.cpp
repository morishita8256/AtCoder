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

bool complete(string& S) {
  bool ok = true;
  rep(i, len(S)) {
    if (S[i] == '.')
      ok = false;
  }
  return ok;
}

signed main() {
  int N, R;
  cin >> N >> R;
  string S;
  cin >> S;

  int ans = 0;
  rep(i, N) {
    if (complete(S))
      break;

    if (S[i] == '.') {
      ans++;
      rep(j, R) {
        if (i + j >= N)
          break;
        S[i + j] = 'o';
      }
    } else {
      bool nokoru = false;
      repp(j, i + R, N - 1) {
        if (S[j] == '.')
          nokoru = true;
      }
      if (!nokoru) {
        ans++;
        rep(j, R) {
          if (i + j >= N)
            break;
          S[i + j] = 'o';
        }
      }
    }

    if (complete(S))
      break;

    ans++;
  }
  cout << ans << "\n";
}