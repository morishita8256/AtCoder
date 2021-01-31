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

#define int ll

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A), greater<int>());

  int temp = -1;
  int a = 0;
  int b = 0;
  bool found = false;
  rep(i, N) {
    if (temp == A[i]) {
      if (a > 0) {
        b = temp;
        found = true;
        break;
      } else {
        a = temp;
        temp = -1;
      }
    } else {
      temp = A[i];
    }
    if (found)
      break;
  }
  cout << a * b << endl;
}