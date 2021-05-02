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
  string S;
  cin >> S;
  if (N % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }

  int n = (N - 1) / 2;
  string temp_r = "bca";
  string temp_l = "bac";
  rep(i, n + 1) {
    char cr = S[n + i];
    char cl = S[n - i];

    char exa_r = temp_r[i % 3];
    char exa_l = temp_l[i % 3];
    if (cr != exa_r || cl != exa_l) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << n << endl;
}