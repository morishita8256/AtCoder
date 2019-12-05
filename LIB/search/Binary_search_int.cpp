#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll LINF = 1001001001001001001ll;


template <class T>
T find_min(T l, T r, bool f(T)) {
  T c;
  while (r - l > 1) {
    c = (r + l) / 2;
    if (f(c)) {
      r = c;
    } else {
      l = c;
    }
  }

  return r;
}

template <class T>
T find_max(T l, T r, bool f(T)) {
  T c;
  while (r - l > 1) {
    c = (r + l) / 2;
    if (f(c)) {
      l = c;
    } else {
      r = c;
    }
  }

  return l;
}

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

  cout << find_min(-1LL, LINF, f) << endl;
}
