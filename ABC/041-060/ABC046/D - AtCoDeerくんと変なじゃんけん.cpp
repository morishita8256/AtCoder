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
  string s;
  cin >> s;

  int N = sz(s);
  string t(N, 'g');
  rep(i, N) {
    if (i % 2)
      t[i] = 'p';
  }

  int ans = 0;
  rep(i, sz(s)) {
    if (s[i] == 'g' && t[i] == 'p')
      ans++;
    else if (s[i] == 'p' && t[i] == 'g')
      ans--;
  }
  cout << ans << endl;
}