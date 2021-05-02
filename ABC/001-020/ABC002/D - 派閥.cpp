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
  int N, M;
  cin >> N >> M;
  vector<int> x(M), y(M);
  rep(i, M) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
  }


  /* 2bit */
  int ans = 0;
  rep(b, bit(N)) {
    vector<int> A(N);
    int num = 0;
    rep(i, N) {
      if ((b >> i) & 1) {
        A[i] = 1;
        num++;
      } else
        A[i] = 0;
    }

    vector<vector<int>> G(N);
    rep(i, M) {
      if (A[x[i]] && A[y[i]]) {
        G[x[i]].pb(y[i]);
        G[y[i]].pb(x[i]);
      }
    }

    bool ok = true;
    rep(i, N) {
      if (!A[i])
        continue;
      if (sz(G[i]) != num - 1)
        ok = false;
    }
    if (ok)
      chmax(ans, num);
  }
  cout << ans << endl;
}