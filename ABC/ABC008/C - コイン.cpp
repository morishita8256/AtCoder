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

#define double long double

int main() {
  int N;
  cin >> N;
  vector<ll> C(N);
  rep(i, N) {
    cin >> C[i];
  }

  double ans = 0.0;
  rep(i, N) {
    int cnt = 0;
    rep(j, N) {
      if (i == j)
        continue;
      if (C[i] % C[j] == 0)
        cnt++;
    }
    ans += (cnt / 2 + 1.0) / (cnt + 1.0);
  }

  printf("%.14Lf\n", ans);  // Lf?
}