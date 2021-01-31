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
  int N, M;
  cin >> N >> M;
  ll X, Y;
  cin >> X >> Y;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];
  vector<ll> b(M);
  rep(i, M) cin >> b[i];

  int ans = 0;
  ll time = 0;
  while (true) {
    auto iter = lower_bound(all(a), time);
    int pos = distance(a.begin(), iter);
    if (iter == a.end())
      break;
    time = a[pos] + X;

    iter = lower_bound(all(b), time);
    pos = distance(b.begin(), iter);
    if (iter == b.end())
      break;
    time = b[pos] + Y;
    ans++;
  }
  cout << ans << endl;
}