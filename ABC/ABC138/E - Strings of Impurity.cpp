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
  string s;
  cin >> s;
  string t;
  cin >> t;

  vector<vector<ll>> s_char_loc(26);
  rep(i, s.size()) {
    char ch = s[i];
    s_char_loc[ch - 'a'].pb(i);
  }


  ll round = 0;
  ll now_ind = -1;
  rep(i, t.size()) {
    char next = t[i];
    vector<ll>& nvec = s_char_loc[next - 'a'];

    if (nvec.size() == 0) {
      cout << -1 << endl;
      return 0;
    }

    auto itr = upper_bound(all(nvec), now_ind);
    if (itr != nvec.end()) {
      now_ind = *itr;
    } else {
      round++;
      now_ind = nvec[0];
    }
  }

  ll ans = round * s.size() + now_ind + 1;
  cout << ans << endl;
}