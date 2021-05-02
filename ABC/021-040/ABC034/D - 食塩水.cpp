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
  ll N, K;
  cin >> N >> K;
  vector<ll> w(N), p(N);
  rep(i, N) cin >> w[i] >> p[i];

  double r = 100.0;
  double l = 0.0;
  double c;

  while (abs(r - l) > 1e-10) {
    c = (r + l) / 2.0;
    vector<double> over(N);
    rep(i, N) {
      over[i] = w[i] * (p[i] - c);
    }
    sort(all(over), greater<>());

    double ov = 0.0;
    rep(i, K) {
      ov += over[i];
    }

    if (ov > 0)
      l = c;
    else if (ov < 0)
      r = c;
    else {
      l = c;
      r = c;
    }
  }

  printf("%.14f\n", c);
}