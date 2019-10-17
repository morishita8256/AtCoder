#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

/* 前処理 O(n) */
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

/* 計算 O(1) */
long long COM(int n, int k) {
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  /* パスカルの三角形 */
  int N;
  ll COM[N + 1][N + 1];
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        COM[i][j] = 1;
      else {
        COM[i][j] = COM[i - 1][j - 1] + COM[i - 1][j];
      }
    }
  }
}
