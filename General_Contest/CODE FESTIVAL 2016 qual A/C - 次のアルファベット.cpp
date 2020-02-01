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

int dist_to_a(char c) {
  if (c == 'a')
    return 0;
  else
    return 26 - (c - 'a');
}

int main() {
  string s;
  cin >> s;
  int K;
  cin >> K;

  string ans;
  rep(i, sz(s)) {
    if (K >= dist_to_a(s[i])) {
      K -= dist_to_a(s[i]);
      ans.pb('a');
    } else
      ans.pb(s[i]);
  }

  if (K > 0) {
    ans[sz(ans) - 1] += (K % 26);
    if (ans[sz(ans) - 1] > 'z')
      ans[sz(ans) - 1] ^= 26;
  }
  cout << ans << endl;
}