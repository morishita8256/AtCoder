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

int main() {
  ll N;
  cin >> N;
  vector<ll> T(N), A(N);
  rep(i, N) cin >> T[i] >> A[i];

  repp(i, 1, N - 1) {
    ll mul = max((T[i - 1] + T[i] - 1) / T[i], (A[i - 1] + A[i] - 1) / A[i]);
    T[i] *= mul;
    A[i] *= mul;
  }
  cout << T[N - 1] + A[N - 1] << endl;
}