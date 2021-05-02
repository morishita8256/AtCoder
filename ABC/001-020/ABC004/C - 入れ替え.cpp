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
#define sz(x) ((ll)(x).size())
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

  int Q = N / 5, R = N % 5;

  vector<int> ans(6);
  Q %= 6;
  rep(i, 6) {
    ans[i] = Q++;
    ans[i] %= 6;
    ans[i]++;
  }

  rep(i, R) {
    swap(ans[i], ans[i + 1]);
  }

  rep(i, sz(ans)) {
    cout << ans[i] << ((i == sz(ans) - 1) ? "\n" : "");
  }
}