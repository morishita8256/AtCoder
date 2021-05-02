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


signed main() {
  int N;
  cin >> N;
  int A, B, C;
  cin >> A >> B >> C;
  vector<string> s(N);
  rep(i, N) {
    cin >> s[i];
  }

  vector<char> ans(N);
  rep(i, N) {
    if (s[i] == "AB") {
      if (A > B) {
        A--, B++, ans[i] = 'B';
      } else if (A < B) {
        B--, A++, ans[i] = 'A';
      } else {
        if (i != N - 1) {
          string ns = s[i + 1];
          if (ns == "AB" || ns == "AC") {
            B--, A++, ans[i] = 'A';
          } else {
            A--, B++, ans[i] = 'B';
          }
        } else {
          B--, A++, ans[i] = 'A';
        }
      }
    } else if (s[i] == "AC") {
      if (A > C) {
        A--, C++, ans[i] = 'C';
      } else if (A < C) {
        C--, A++, ans[i] = 'A';
      } else {
        if (i != N - 1) {
          string ns = s[i + 1];
          if (ns == "AB" || ns == "AC") {
            C--, A++, ans[i] = 'A';
          } else {
            A--, C++, ans[i] = 'C';
          }
        } else {
          C--, A++, ans[i] = 'A';
        }
      }
    } else {
      if (B > C) {
        B--, C++, ans[i] = 'C';
      } else if (B < C) {
        C--, B++, ans[i] = 'B';
      } else {
        if (i != N - 1) {
          string ns = s[i + 1];
          if (ns == "AB" || ns == "BC") {
            C--, B++, ans[i] = 'B';
          } else {
            B--, C++, ans[i] = 'C';
          }
        } else {
          C--, B++, ans[i] = 'B';
        }
      }
    }
    if (A < 0 || B < 0 || C < 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  rep(i, len(ans)) {
    cout << ans[i] << endl;
  }
}
