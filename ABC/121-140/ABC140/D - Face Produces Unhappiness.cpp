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
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  int lr = 0;
  int rl = 0;
  int ans = 0;
  rep(i, N - 1) {
    if (S[i] == 'R' && S[i + 1] == 'L')
      rl++;
    if (S[i] == 'L' && S[i + 1] == 'R')
      lr++;
    if (S[i] == S[i + 1])
      ans++;
  }
  rep(i, K) {
    if (lr > 0 && rl > 0) {
      ans += 2;
      lr--;
      rl--;
    } else if (lr + rl == 1) {
      ans++;
      break;
    } else
      break;
  }
  cout << ans << endl;
}