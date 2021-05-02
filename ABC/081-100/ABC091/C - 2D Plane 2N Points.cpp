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

  typedef pair<int, int> P;

  vector<P> ab(N);
  rep(i, N) cin >> ab[i].fi >> ab[i].se;
  vector<P> cd(N);
  rep(i, N) cin >> cd[i].fi >> cd[i].se;

  sort(all(cd));

  vector<bool> used_ab(N, false);

  int ans = 0;
  rep(i, N) {
    int ymax = -1;
    int ymax_ind = -1;

    rep(j, N) {
      if (ab[j].fi < cd[i].fi && ab[j].se < cd[i].se && used_ab[j] == false) {
        if (chmax(ymax, ab[j].se)) ymax_ind = j;
      }
    }

    if (ymax_ind != -1) {
      used_ab[ymax_ind] = true;
      ans++;
    }
  }
  cout << ans << endl;
}