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

ll N, X;
vector<ll> B, P, A;

ll p(ll n, ll x) {
  if (n == 0)
    return 1;

  if (x == 0) {
    return 0;
  } else if (x <= A[n - 1]) {
    return p(n - 1, x - 1);
  } else if (x == A[n - 1] + 1) {
    return P[n - 1] + 1;
  } else if (x <= 2 * A[n - 1] + 1) {
    return P[n - 1] + 1 + p(n - 1, x - (A[n - 1] + 2));
  } else {
    return 2 * P[n - 1] + 1;
  }
}

int main() {
  cin >> N >> X;
  X--;  // 0-origin

  B = vector<ll>(N + 1);
  P = vector<ll>(N + 1);
  A = vector<ll>(N + 1);

  B[0] = 0;
  P[0] = 1;
  A[0] = 1;
  rep(i, N) {
    B[i + 1] = B[i] * 2 + 2;
    P[i + 1] = P[i] * 2 + 1;
    A[i + 1] = A[i] * 2 + 3;
  }

  cout << p(N, X) << endl;
}