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

int bit3(int n) {
  int temp = 1;
  rep(i, n) {
    temp *= 3;
  }
  return temp;
}

int shift3(int b, int n) {
  rep(i, n) {
    b /= 3;
  }
  return b;
}

int main() {
  int N;
  N = 3;

  /* 2bit */
  vector<int> A(N);
  rep(b, bit(N)) {
    rep(i, N) {
      if ((b >> i) & 1)
        A[i] = 1;
      else
        A[i] = 0;
      cout << A[i];
    }
    cout << endl;
  }

  /* 3bit */
  vector<int> B(N);
  rep(b, bit3(N)) {
    rep(i, N) {
      B[i] = shift3(b, i) % 3;  // 0 or 1 or 2
      cout << B[i];
    }
    cout << endl;
  }
}