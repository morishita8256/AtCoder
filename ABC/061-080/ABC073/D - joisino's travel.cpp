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
  int N, M, R;
  cin >> N >> M >> R;

  vector<int> r(R);
  rep(i, R) {
    cin >> r[i];
    r[i]--;
  }

  vector<vector<int>> d(N, vector<int>(N, INF));

  vector<int> A(M), B(M), C(M);
  rep(i, M) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--;
    B[i]--;
    d[A[i]][B[i]] = C[i];
    d[B[i]][A[i]] = C[i];
  }
  rep(i, N) {
    d[i][i] = 0;
  }

  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int perm = 1;
  repp(i, 1, R) {
    perm *= i;
  }

  int ans = INF;
  for (int i = 0; i < perm; ++i) {
    int temp = 0;
    rep(j, R - 1) {
      temp += d[r[j]][r[j + 1]];
    }
    chmin(ans, temp);
    next_permutation(r.begin(), r.end());
  }

  cout << ans << endl;
}