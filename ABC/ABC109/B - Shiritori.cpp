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
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  vector<string> W(N);
  rep(i, N) cin >> W[i];
  map<string, int> m;
  char hip = W[0][0];
  rep(i, N) {
    if (m.find(W[i]) != m.end()) {
      cout << "No" << endl;
      return 0;
    }
    if (W[i][0] != hip) {
      cout << "No" << endl;
      return 0;
    }
    m[W[i]] = 1;
    hip = W[i][W[i].size() - 1];
  }
  cout << "Yes" << endl;
}