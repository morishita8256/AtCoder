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
  string S;
  cin >> S;
  int N = len(S);

  int ans = 0;

  // 1
  set<char> st;
  for (char c : S)
    st.insert(c);
  ans += len(st) + 1;

  char dot = 'z' + 1;


  // 2
  if (N >= 2) {
    rep(i, 27) {
      rep(j, 27) {
        char ii = 'a' + i, jj = 'a' + j;
        rep(s, N - 1) {
          if ((ii == dot || ii == S[s]) && (jj == dot || jj == S[s + 1])) {
            ans++;
            break;
          }
        }
      }
    }
  }


  // 3
  if (N >= 3) {
    rep(i, 27) {
      rep(j, 27) {
        rep(k, 27) {
          char ii = 'a' + i, jj = 'a' + j, kk = 'a' + k;
          rep(s, N - 2) {
            if ((ii == dot || ii == S[s]) && (jj == dot || jj == S[s + 1]) &&
                (kk == dot || kk == S[s + 2])) {
              ans++;
              break;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}