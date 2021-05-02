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
  int mx = -INF, mn = INF;
  int mx_ind, mn_ind;
  rep(i, N) {
    cin >> a[i];
    if (chmax(mx, a[i]))
      mx_ind = i;
    if (chmin(mn, a[i]))
      mn_ind = i;
  }

  cout << (2 * N - 1) << endl;
  if (mx + mn >= 0) {
    rep(i, N) {
      if (i != mx_ind)
        cout << (mx_ind + 1) << ' ' << (i + 1) << endl;
    }
    cout << (mx_ind + 1) << ' ' << (mx_ind + 1) << endl;
    rep(i, N - 1) {
      cout << (i + 1) << ' ' << (i + 2) << endl;
    }
  } else {
    rep(i, N) {
      if (i != mn_ind)
        cout << (mn_ind + 1) << ' ' << (i + 1) << endl;
    }
    cout << (mn_ind + 1) << ' ' << (mn_ind + 1) << endl;
    repr(i, N - 1, 1) {
      cout << (i + 1) << ' ' << i << endl;
    }
  }
}