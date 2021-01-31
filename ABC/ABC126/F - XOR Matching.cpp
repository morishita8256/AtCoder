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
  int M, K;
  cin >> M >> K;

  if (M == 0) {
    if (K == 0)
      cout << "0 0" << endl;
    else
      cout << -1 << endl;
    return 0;
  }

  if (M == 1) {
    if (K == 0)
      cout << "0 0 1 1" << endl;
    else
      cout << -1 << endl;
    return 0;
  }

  int N = 1;
  rep(i, M) {
    N *= 2;
  }

  if (K >= N) {
    cout << -1 << endl;
    return 0;
  }

  rep(i, N) {
    if (i == K)
      continue;
    cout << i << ' ';
  }

  cout << K << ' ';

  rep(i, N) {
    int j = N - 1 - i;
    if (j == K)
      continue;
    cout << j << ' ';
  }

  cout << K << endl;
}