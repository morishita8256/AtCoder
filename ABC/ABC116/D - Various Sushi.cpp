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
  int N, K;
  cin >> N >> K;

  typedef pair<ll, int> P;
  vector<P> dt(N);
  rep(i, N) {
    cin >> dt[i].se >> dt[i].fi;
    (dt[i].se)--;
  }

  sort(all(dt), greater<P>());

  priority_queue<P, vector<P>, greater<P>>
      dupli;  // 同種で2個以上あるものだけ持っておく
  vector<int> cnt(N);

  ll del = 0;
  ll kind = 0;  // intだと死ぬ
  rep(i, K) {
    int t = dt[i].se;
    ll d = dt[i].fi;

    del += d;

    if (cnt[t] == 0)
      kind++;
    else
      dupli.push(dt[i]);
    cnt[t]++;
  }

  ll ans = del + kind * kind;
  repp(i, K, N - 1) {
    if (dupli.empty())
      break;
    int t = dt[i].se;
    ll d = dt[i].fi;

    if (cnt[t] > 0)
      continue;
    kind++;

    int ch_t = dupli.top().se;
    ll ch_d = dupli.top().fi;
    dupli.pop();

    cnt[t]++;
    del += d;

    cnt[ch_t]--;
    del -= ch_d;

    chmax(ans, del + kind * kind);
  }
  cout << ans << endl;
}