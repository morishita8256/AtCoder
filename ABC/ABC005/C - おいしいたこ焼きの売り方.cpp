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
  int T;
  cin >> T;
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }
  int M;
  cin >> M;
  vector<int> B(M);
  rep(i, M) {
    cin >> B[i];
  }

  int ind = 0;
  rep(i, M) {
    if (ind >= N) {
      cout << "no" << endl;
      return 0;
    }
    if (B[i] < A[ind]) {
      cout << "no" << endl;
      return 0;
    }

    while (B[i] > A[ind] + T) {
      ind++;
      if (ind == N) {
        cout << "no" << endl;
        return 0;
      }
    }
    ind++;
  }
  cout << "yes" << endl;
}