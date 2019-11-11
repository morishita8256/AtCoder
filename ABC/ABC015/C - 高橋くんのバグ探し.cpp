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
  int N, K;
  cin >> N >> K;
  vector<vector<int>> T(N, vector<int>(K));
  rep(i, N) {
    rep(j, K) {
      cin >> T[i][j];
    }
  }

  /* Kbit */
  rep(b, bitK(N, K)) {
    int score = 0;
    rep(i, N) {
      int temp = shiftK(b, i, K) % K;  // 0 ... K-1
      score ^= T[i][temp];
    }
    if (score == 0) {
      cout << "Found" << endl;
      return 0;
    }
  }
  cout << "Nothing" << endl;
}