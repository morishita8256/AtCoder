#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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
  int N;
  cin >> N;
  vector<ll> H(N);
  rep(i, N) cin >> H[i];

  reverse(all(H));
  int ans = 0;
  int cnt = 0;
  int temp_H = 0;
  int i = 0;
  while (i < N) {
    if (temp_H <= H[i])
      cnt++;
    else {
      chmax(ans, cnt);
      cnt = 1;
    }
    temp_H = H[i];
    i++;
  }
  chmax(ans, cnt);

  ans = max(ans - 1, 0);
  cout << ans << endl;
}