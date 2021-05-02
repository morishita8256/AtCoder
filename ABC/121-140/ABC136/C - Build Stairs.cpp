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
  vector<int> H(N);
  rep(i, N) cin >> H[i];

  vector<int> diff(N - 1);
  rep(i, N - 1) { diff[i] = H[i + 1] - H[i]; }

  int minus_one = false;
  rep(i, N - 1) {
    if (diff[i] >= 1) {
      minus_one = false;
    } else if (diff[i] <= -2) {
      cout << "No" << endl;
      return 0;
    } else if (diff[i] == -1) {
      if (minus_one) {
        cout << "No" << endl;
        return 0;
      } else {
        minus_one = true;
      }
    }
  }
  cout << "Yes" << endl;
}