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
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  rep(i, M) cin >> B[i];
  vector<vector<int>> A(N, vector<int>(M));
  rep(i, N) {
    rep(j, M) {
      cin >> A[i][j];
    }
  }

  int ans = 0;
  rep(i, N) {
    int temp = 0;
    rep(j, M) {
      temp += A[i][j] * B[j];
    }
    temp += C;
    if (temp > 0)
      ans++;
  }
  cout << ans << endl;
}