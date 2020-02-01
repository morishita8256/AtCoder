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
  ll T1, T2;
  cin >> T1 >> T2;
  ll A1, A2;
  cin >> A1 >> A2;
  ll B1, B2;
  cin >> B1 >> B2;

  if (A1 < B1) {
    swap(A1, B1);
    swap(A2, B2);
  }

  ll C1 = (A1 - B1) * T1, C2 = (A2 - B2) * T2;

  if (C1 + C2 == 0) {
    cout << "infinity" << endl;
    return 0;
  }

  if (C1 + C2 > 0) {
    cout << 0 << endl;
    return 0;
  }

  ll D = -(C1 + C2);
  ll ans;
  if (C1 % D == 0) {
    ans = (C1 / D - 1) * 2 + 2;
  } else {
    ans = (C1 / D) * 2 + 1;
  }


  cout << ans << endl;
}