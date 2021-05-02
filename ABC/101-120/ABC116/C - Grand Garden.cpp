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
  vector<int> h(N);
  rep(i, N) cin >> h[i];
  int ans = 0;
  while (true) {
    int temp = 0;

    rep(i, N - 1) {
      if (h[i] > 0 && h[i + 1] <= 0) temp++;
    }

    if (h[N - 1] > 0) temp++;

    if (temp == 0) break;
    ans += temp;
    rep(i, N) { h[i]--; }
  }
  cout << ans << endl;
}