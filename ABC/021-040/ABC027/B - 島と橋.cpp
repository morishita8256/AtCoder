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
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  int sum = 0;
  rep(i, N) {
    sum += a[i];
  }

  if (sum % N != 0) {
    cout << -1 << endl;
    return 0;
  }

  int base = sum / N;

  sum = 0;
  int island = 0;
  int ans = 0;
  rep(i, N) {
    island++;
    sum += a[i];
    if (island * base == sum) {
      sum = 0;
      island = 0;
    } else {
      ans++;
    }
  }
  cout << ans << endl;
}