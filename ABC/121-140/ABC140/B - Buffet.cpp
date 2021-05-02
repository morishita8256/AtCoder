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
  int N;
  cin >> N;
  vector<int> A(N);

  rep(i, N) {
    cin >> A[i];
    A[i]--;
  }

  int ans = 0;

  vector<int> B(N);
  rep(i, N) {
    cin >> B[i];
    ans += B[i];
  }

  vector<int> C(N - 1);
  rep(i, N - 1) cin >> C[i];

  rep(i, N - 1) {
    if (A[i] + 1 == A[i + 1])
      ans += C[A[i]];
  }

  cout << ans << endl;
}