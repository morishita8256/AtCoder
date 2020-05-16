#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll LINF = 1001001001001001001ll;

// 引数は(ok, ng)
#pragma region bin_search
bool f(ll trial);
template <class T>
T bin_search(T ok, T ng) {
  T c;
  while (abs(ok - ng) > 1) {
    c = (ok + ng) / 2;
    if (f(c)) {
      ok = c;
    } else {
      ng = c;
    }
  }

  return ok;
}
#pragma endregion

/*
https://atcoder.jp/contests/abc144/tasks/abc144_e
*/
ll N, K;
vector<ll> A;
vector<ll> F;

bool f(ll trial) {
  ll shugyo = 0;
  rep(i, N) {
    ll multi = A[i] * F[i];
    if (multi <= trial)
      continue;
    multi -= trial;
    multi = (multi + F[i] - 1) / F[i];
    shugyo += multi;
  }
  return (shugyo <= K);
}

int main() {
  cin >> N >> K;
  A = vector<ll>(N);
  F = vector<ll>(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> F[i];

  sort(all(A));
  sort(all(F), greater<ll>());

  cout << bin_search(LINF, -1ll) << endl;
}
