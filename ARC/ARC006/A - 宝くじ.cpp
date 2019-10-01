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
  vector<int> E(10);
  int EE;
  rep(i, 6) {
    cin >> EE;
    E[EE]++;
  }
  int B;
  cin >> B;
  vector<int> L(10);
  int LL;
  rep(i, 6) {
    cin >> LL;
    L[LL]++;
  }
  int match = 0;
  rep(i, 10) {
    if (E[i] && L[i])
      match++;
  }

  if (match == 6) {
    cout << 1 << endl;
  } else if (match == 5) {
    int not_match;
    rep(i, 10) {
      if (L[i] && (!E[i]))
        not_match = i;
    }
    if (not_match == B) {
      cout << 2 << endl;
      return 0;
    }
    cout << 3 << endl;
  } else if (match == 4) {
    cout << 4 << endl;
  } else if (match == 3) {
    cout << 5 << endl;
  } else {
    cout << 0 << endl;
  }
}