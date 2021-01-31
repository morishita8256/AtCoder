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

int bit3(int n) {
  int temp = 1;
  rep(i, n) {
    temp *= 3;
  }
  return temp;
}

int shift3(int b, int n) {
  rep(i, n) {
    b /= 3;
  }
  return b;
}

int main() {
  int N;
  cin >> N;

  rep(b, bit3(N)) {
    string ans(N, '.');
    rep(i, N) {
      ans[i] = shift3(b, i) % 3 + 'a';  // 0 or 1 or 2
    }
    reverse(all(ans));
    cout << ans << endl;
  }
}