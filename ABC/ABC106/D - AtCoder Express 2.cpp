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
  int N, M, Q;
  cin >> N >> M >> Q;

  vector<vector<int>> LR(N, vector<int>(N));

  vector<int> L(M), R(M);
  rep(i, M) {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
    LR[L[i]][R[i]]++;
  }
  vector<int> p(Q), q(Q);
  rep(i, Q) {
    cin >> p[i] >> q[i];
    p[i]--;
    q[i]--;
  }

  vector<vector<int>> sum(N, vector<int>(N));
  rep(i, N) {
    rep(j, N) {
      sum[i][j] = LR[i][j];
      if (i > 0)
        sum[i][j] += sum[i - 1][j];
      if (j > 0)
        sum[i][j] += sum[i][j - 1];
      if (i > 0 && j > 0)
        sum[i][j] -= sum[i - 1][j - 1];
    }
  }

  rep(i, Q) {
    int ans = sum[q[i]][q[i]];
    if (p[i] > 0) {
      ans -= sum[p[i] - 1][q[i]];
      ans -= sum[q[i]][p[i] - 1];
      ans += sum[p[i] - 1][p[i] - 1];
    }
    cout << ans << endl;
  }
}