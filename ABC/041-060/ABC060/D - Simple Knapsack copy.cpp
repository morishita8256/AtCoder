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
  ll W;
  cin >> N >> W;
  vector<ll> w(N), v(N);
  rep(i, N) cin >> w[i] >> v[i];

  vector<vector<ll>> V(4);
  rep(i, N) {
    V[w[i] - w[0]].pb(v[i]);
  }

  vector<int> num(4);
  rep(i, N) {
    num[i] = sz(V[i]);
    sort(all(V[i]), greater<ll>());
  }

  ll ans = 0;
  rep(i0, num[0] + 1) {
    rep(i1, num[1] + 1) {
      rep(i2, num[2] + 1) {
        rep(i3, num[3] + 1) {
          ll weight =
              i0 * w[0] + i1 * (w[0] + 1) + i2 * (w[0] + 2) + i3 * (w[0] + 3);
          if (weight > W)
            continue;

          ll temp = 0;
          rep(i, i0) {
            temp += V[0][i];
          }
          rep(i, i1) {
            temp += V[1][i];
          }
          rep(i, i2) {
            temp += V[2][i];
          }
          rep(i, i3) {
            temp += V[3][i];
          }

          chmax(ans, temp);
        }
      }
    }
  }
  cout << ans << endl;
}