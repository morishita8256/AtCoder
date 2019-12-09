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
#define sz(x) ((ll)(x).size())
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
  /* 1D */
  int mx1 = 3;  //

  int nm1 = mx1 * 2;
  int dp1_[nm1];
  fill((int*)dp1_, (int*)(dp1_ + mx1), 0);  //

  int* dp1 = &(dp1_[mx1]);


  /* 2D */
  int H2 = 2;   //
  int mx2 = 3;  //

  int nm2 = mx2 * 2 + 1;
  int dp2_[H2][nm2];
  fill((int*)dp2_, (int*)(dp2_ + H2), 0);  //

  int* dp2[H2];
  rep(i, H2) {
    dp2[i] = &(dp2_[i][mx2]);
  }


  /* 3D */
  int H3 = 2, W3 = 5;  //
  int mx3 = 3;         //

  int nm3 = mx3 * 2 + 1;
  int dp3_[H3][W3][nm3];
  fill((int*)dp3_, (int*)(dp3_ + H3), 0);  //

  int* dp3[H3][W3];
  rep(i, H3) {
    rep(j, W3) {
      dp3[i][j] = &(dp3_[i][j][mx3]);
    }
  }
}