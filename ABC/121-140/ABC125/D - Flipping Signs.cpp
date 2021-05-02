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
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;

  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  ll sum = 0;
  int num_of_minus = 0;
  ll min_abs = 1e+10;

  rep(i, N) {
    sum += abs(A[i]);
    num_of_minus += (A[i] < 0);
    chmin(min_abs, abs(A[i]));
  }

  if (num_of_minus % 2 == 1) {
    sum -= 2 * min_abs;
  }

  cout << sum << endl;
}