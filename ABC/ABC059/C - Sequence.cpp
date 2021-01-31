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

ll sign(ll A) {
  return (A > 0) - (A < 0);
}

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];

  ll ans_1 = 0;
  ll sum = 0;
  int sig = 1;
  rep(i, N) {
    sum += a[i];
    if (sig * sum <= 0) {
      ll diff = sig - sum;
      sum += diff;
      ans_1 += abs(diff);
    }
    sig *= -1;
  }

  ll ans_2 = 0;
  sum = 0;
  sig = -1;
  rep(i, N) {
    sum += a[i];
    if (sig * sum <= 0) {
      ll diff = sig - sum;
      sum += diff;
      ans_2 += abs(diff);
    }
    sig *= -1;
  }

  cout << min(ans_1, ans_2) << endl;
}