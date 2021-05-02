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

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  vector<int> s;
  vector<int> g;

  rep(i, M) {
    cin >> a[i] >> b[i];
    if (a[i] == 1)
      s.pb(b[i]);
    if (b[i] == N)
      g.pb(a[i]);
  }
  sort(all(g));

  rep(i, s.size()) {
    if (binary_search(all(g), s[i])) {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}