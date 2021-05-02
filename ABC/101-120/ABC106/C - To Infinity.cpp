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
  string S;
  cin >> S;
  ll K;
  cin >> K;

  int not_one_ind = 0;
  int not_one = 0;

  rep(i, S.size()) {
    if (S[i] - '0' != 1) {
      not_one_ind = i;
      not_one = S[i] - '0';
      break;
    }
  }
  if (not_one == 0) {
    cout << 1 << endl;
    return 0;
  }
  if (K - 1 < not_one_ind) {
    cout << 1 << endl;
  } else {
    cout << not_one << endl;
  }
}