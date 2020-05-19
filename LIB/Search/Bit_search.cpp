#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL << (n))

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}


// 3-bit
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

// K-bit
int bitK(int n, int K) {
  int temp = 1;
  rep(i, n) {
    temp *= K;
  }
  return temp;
}

int shiftK(int b, int n, int K) {
  rep(i, n) {
    b /= K;
  }
  return b;
}

int main() {
  int N;
  N = 3;

  /* 2bit */
  rep(b, bit(N)) {
    int num = __builtin_popcount(b);
    vector<int> A(N);
    rep(i, N) {
      if ((b >> i) & 1)
        A[i] = 1;
      else
        A[i] = 0;
    }
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

  int K = 4;
  /* Kbit */
  vector<int> C(N);
  rep(b, bitK(N, K)) {
    rep(i, N) {
      C[i] = shiftK(b, i, K) % K;  // 0 or ... or K-1
      cout << C[i];
    }
    cout << endl;
  }
}