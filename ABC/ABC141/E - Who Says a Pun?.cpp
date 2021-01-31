#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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
  int N;
  cin >> N;
  string S;
  cin >> S;

  int ans = 0;
  repp(diff, 1, N - 1) {
    int temp = 0;
    int temp_max = 0;
    rep(i, N - diff) {
      if (S[i] == S[i + diff]) {
        temp++;
      } else {
        chmax(temp_max, temp);
        temp = 0;
      }
      chmax(temp_max, temp);
    }
    chmax(ans, min(temp_max, diff));
  }

  cout << ans << endl;
}