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

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  sort(all(A), greater<ll>());
  vector<ll> B(N);
  int a = 1;
  int b = 0;
  rep(i, N / 2) {
    B[a] = A[b++];
    a += 2;
  }

  if (N % 2)
    B[N - 1] = A[b++];

  a = 0;
  rep(i, N / 2) {
    B[a] = A[b++];
    a += 2;
  }

  ll ans_1 = 0;
  rep(i, N - 1) {
    ans_1 += abs(B[i] - B[i + 1]);
  }

  sort(all(A));
  a = 1;
  b = 0;
  rep(i, N / 2) {
    B[a] = A[b++];
    a += 2;
  }

  if (N % 2)
    B[N - 1] = A[b++];

  a = 0;
  rep(i, N / 2) {
    B[a] = A[b++];
    a += 2;
  }

  ll ans_2 = 0;
  rep(i, N - 1) {
    ans_2 += abs(B[i] - B[i + 1]);
  }

  ll ans = max(ans_1, ans_2);
  cout << ans << endl;
}