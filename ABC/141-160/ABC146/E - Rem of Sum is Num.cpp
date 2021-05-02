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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
    A[i]--;
    A[i] %= K;
  }

  vector<int> S(N + 1);
  rep(i, N) {
    S[i + 1] = S[i] + A[i];
    S[i + 1] %= K;
  }


  map<ll, ll> m;
  ll ans = 0;
  rep(i, N + 1) {
    ll ii = i;
    ll temp = S[i];
    m[temp]++;

    if (ii - K >= 0)
      m[S[ii - K]]--;

    ans += m[temp] - 1;
  }

  cout << ans << endl;
}