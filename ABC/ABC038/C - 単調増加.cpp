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
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  a.pb(INF);

  ll ans = 0;

  int temp_num = 0;
  ll temp_cnt = 0;
  int i = 0;
  while (i < N) {
    if (a[i] > temp_num) {
      temp_cnt++;
    } else {
      ans += temp_cnt * (temp_cnt + 1) / 2;
      temp_cnt = 1;
    }
    temp_num = a[i];
    i++;
  }
  ans += temp_cnt * (temp_cnt + 1) / 2;
  cout << ans << endl;
}