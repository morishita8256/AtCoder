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
  int N, M;
  cin >> N >> M;
  typedef pair<int, int> P;

  vector<P> BA(N);
  rep(i, N) {
    cin >> BA[i].se >> BA[i].fi;
    BA[i].se *= -1;
  }
  sort(all(BA), greater<P>());

  rep(i, N) { BA[i].se *= -1; }

  set<int> s;
  repp(i, 1, M) { s.insert(i); }

  ll ans = 0;
  rep(i, N) {
    set<int>::iterator it = s.lower_bound(BA[i].se);
    if (it == s.end())
      continue;
    else {
      s.erase(it);
      ans += BA[i].fi;
    }
  }
  cout << ans << endl;
}