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

ll N, A, B;
vector<ll> h;

// O(N)
bool can_kill(ll times) {
  ll cnt = 0;
  rep(i, N) {
    ll res = h[i] - times * B;
    if (res > 0)
      cnt += (res + (A - B - 1)) / (A - B);
  }
  if (cnt <= times)
    return true;
  else
    return false;
}

int main() {
  cin >> N >> A >> B;
  h = vector<ll>(N);
  rep(i, N) cin >> h[i];

  ll l = 0;
  ll r = 1.0e+10;

  while (r - l > 1) {
    ll c = (r + l) / 2;
    if (can_kill(c))
      r = c;
    else
      l = c;
  }

  cout << r << endl;
}