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

struct edge {
  int to, cost;
  edge(int to, int cost) : to(to), cost(cost) {}
};

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> c(10, vector<int>(10));
  rep(i, 10) {
    rep(j, 10) {
      cin >> c[i][j];
    }
  }

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++)
        c[j][k] = min(c[j][k], c[j][i] + c[i][k]);

  vector<int> cnt(10);
  vector<vector<int>> A(H, vector<int>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
      if (A[i][j] == -1)
        continue;
      cnt[A[i][j]]++;
    }
  }

  int ans = 0;
  rep(i, 10) {
    ans += c[i][1] * cnt[i];
  }
  cout << ans << endl;
}