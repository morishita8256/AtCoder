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
  cin >> N;
  vector<ll> A(N), B(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
  }
  typedef pair<ll, pair<ll, ll> > P;
  vector<P> C(N);
  rep(i, N) {
    C[i].se.fi = A[i];
    C[i].se.se = B[i];
    C[i].fi = A[i] + B[i];
  }

  sort(all(C), greater<P>());

  ll AA = 0, BB = 0;
  rep(i, sz(C)) {
    if (i % 2)
      BB += C[i].se.se;
    else
      AA += C[i].se.fi;
  }

  ll ans = AA - BB;
  cout << ans << endl;
}