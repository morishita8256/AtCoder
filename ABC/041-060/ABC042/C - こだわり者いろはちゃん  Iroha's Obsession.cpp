#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

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

int main() {
  int N, K;
  cin >> N >> K;
  vector<char> D(K);
  rep(i, K) cin >> D[i];

  repp(i, N, (int)1e+6) {
    string s = to_string(i);
    bool ok = true;
    rep(j, s.size()) {
      rep(k, K) {
        if (s[j] == D[k])
          ok = false;
      }
    }
    if (ok) {
      cout << s << endl;
      return 0;
    }
  }
}