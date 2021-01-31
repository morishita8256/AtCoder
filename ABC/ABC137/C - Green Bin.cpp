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
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  vector<vector<ll>> num(N, vector<ll>(26));
  rep(i, N) {
    cin >> s[i];
    sort(all(s[i]));
  }
  sort(all(s));
  ll ans = 0;

  ll seq = 1;
  repp(i, 1, N - 1) {
    if (s[i] == s[i - 1])
      seq++;
    else {
      ans += seq * (seq - 1) / 2;
      seq = 1;
    }
  }
  ans += seq * (seq - 1) / 2;

  cout << ans << endl;
}