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
#define sz(x) ((int)(x).size())
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
  string S;
  cin >> S;
  S.pb('+');

  bool temp_zero = false;
  int ans = 0;
  rep(i, sz(S)) {
    if (i % 2 == 0) {  // num
      int num = S[i] - '0';
      if (num == 0)
        temp_zero = true;
    } else {  // ope
      if (S[i] == '+') {
        if (!temp_zero) {
          ans++;
        }
        temp_zero = false;
      }
    }
  }
  cout << ans << endl;
}