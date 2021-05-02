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
  int P, Q;
  cin >> P >> Q;
  int R;
  cin >> R;
  vector<int> x(R), y(R), z(R);
  rep(i, R) {
    cin >> x[i] >> y[i] >> z[i];
    x[i]--, y[i]--;
  }

  vector<vector<int>> zz(N, vector<int>(M));
  rep(i, R) {
    zz[x[i]][y[i]] = z[i];
  }

  int ans = 0;
  rep(b, bit(N)) {
    vector<int> xx(N);
    int PP = 0;
    rep(i, N) {
      if ((b >> i) & 1) {
        xx[i] = 1;
        PP++;
      } else
        xx[i] = 0;
    }
    if (PP != P)
      continue;

    vector<int> zzz(M);
    rep(y, M) {
      rep(x, N) {
        if (!xx[x])
          continue;
        zzz[y] += zz[x][y];
      }
    }
    sort(all(zzz), greater<int>());
    int temp = 0;
    rep(i, Q) {
      temp += zzz[i];
    }
    chmax(ans, temp);
  }
  cout << ans << endl;
}