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
  int a, b;
  cin >> a >> b;

  int seq = b;
  if (b == 100) {
    seq += a * 1000;
  } else if (b >= 10) {
    seq += a * 100;
  } else {
    seq += a * 10;
  }

  for (int i = (int)sqrt(seq) - 2; i <= (int)sqrt(seq) + 2; i++) {
    if (i * i == seq) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}