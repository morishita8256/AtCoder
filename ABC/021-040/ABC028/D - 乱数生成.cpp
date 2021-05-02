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
  double N, K;
  cin >> N >> K;

  double ans = 0.0;

  /* (A, B, C) */
  double temp = 6.0;
  temp *= 1.0 / N;
  temp *= (double)(K - 1) / N;
  temp *= (double)(N - K) / N;
  ans += temp;

  /* (A, A, B) */
  temp = 3.0;
  temp *= 1.0 / N;
  temp *= 1.0 / N;
  temp *= (double)(N - 1) / N;
  ans += temp;

  /* (A, A, A) */
  temp = pow(1.0 / N, 3);
  ans += temp;

  printf("%.14f\n", ans);
}