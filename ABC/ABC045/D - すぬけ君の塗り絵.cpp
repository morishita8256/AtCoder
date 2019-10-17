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
  ll H, W, N;
  cin >> H >> W >> N;
  vector<ll> a(N), b(N);
  rep(i, N) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  typedef pair<ll, ll> P;
  set<P> s;

  vector<ll> ans(10);
  ans[0] = (H - 2) * (W - 2);
  rep(n, N) {
    repp(i, max(a[n] - 1, 1LL), min(a[n] + 1, H - 2)) {
      repp(j, max(b[n] - 1, 1LL), min(b[n] + 1, W - 2)) {
        int cnt = 0;
        repp(ii, -1, 1) {
          repp(jj, -1, 1) {
            if (s.find(mp(i + ii, j + jj)) != s.end())
              cnt++;
          }
        }
        ans[cnt]--;
        ans[cnt + 1]++;
      }
    }
    s.insert(mp(a[n], b[n]));
  }

  rep(i, 10) {
    cout << ans[i] << endl;
  }
}