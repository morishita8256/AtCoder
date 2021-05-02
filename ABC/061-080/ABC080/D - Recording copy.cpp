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
  int N, C;
  cin >> N >> C;
  vector<vector<int>> program(C, vector<int>(200000 + 2));

  int s, t, c;
  rep(i, N) {
    cin >> s >> t >> c;
    c--;
    s = s * 2 - 1;
    t = t * 2 - 1;
    repp(j, s, t) {
      program[c][j] = 1;
    }
  }

  int ans = 0;
  repp(i, 1, 200000) {
    int temp = 0;
    rep(j, C) {
      temp += program[j][i];
    }
    chmax(ans, temp);
  }
  cout << ans << endl;
}