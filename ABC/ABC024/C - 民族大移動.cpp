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
  int N, D, K;
  cin >> N >> D >> K;
  vector<int> L(D), R(D);
  rep(i, D) {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
  }
  vector<int> S(K), T(K);
  rep(i, K) {
    cin >> S[i] >> T[i];
    S[i]--;
    T[i]--;
  }

  rep(k, K) {
    int pos = S[k];
    int goal = T[k];

    if (pos < goal) {
      rep(d, D) {
        int l = L[d], r = R[d];
        if (l <= pos && pos <= r)
          pos = r;
        if (pos >= goal) {
          cout << d + 1 << endl;
          break;
        }
      }
    } else {
      rep(d, D) {
        int l = L[d], r = R[d];
        if (l <= pos && pos <= r)
          pos = l;
        if (pos <= goal) {
          cout << d + 1 << endl;
          break;
        }
      }
    }
  }
}