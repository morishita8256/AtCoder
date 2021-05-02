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
  vector<int> P(5);
  rep(i, 5) cin >> P[i];
  int last_ind;
  int min_one = 10;
  rep(i, 5) {
    if (chmin(min_one, (P[i] + 9) % 10)) last_ind = i;
  }
  int ans = 0;
  rep(i, 5) {
    if (i != last_ind) ans += ((P[i] + 9) / 10) * 10;
  }
  ans += P[last_ind];
  cout << ans << endl;
}