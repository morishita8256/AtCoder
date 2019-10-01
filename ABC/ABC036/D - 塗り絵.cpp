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

vector<vector<int>> G;

int main() {
  int N;
  cin >> N;
  vector<int> a(N - 1), b(N - 1);
  G = vector<vector<int>>(N);
  rep(i, N - 1) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    G[a[i]].pb(b[i]);
    G[b[i]].pb(a[i]);
  }
}