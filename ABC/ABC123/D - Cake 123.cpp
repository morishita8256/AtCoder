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
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int K;
  cin >> K;

  vector<ll> A(X);
  rep(i, X) cin >> A[i];
  vector<ll> B(Y);
  rep(i, Y) cin >> B[i];
  vector<ll> C(Z);
  rep(i, Z) cin >> C[i];

  vector<ll> AB(X * Y);
  rep(x, X) {
    rep(y, Y) { AB[x * Y + y] = A[x] + B[y]; }
  }
  sort(all(AB), greater<ll>());

  int XY = min(3000, X * Y);

  vector<ll> ABC(XY * Z);
  rep(xy, XY) {
    rep(z, Z) { ABC[xy * Z + z] = AB[xy] + C[z]; }
  }

  sort(all(ABC), greater<ll>());

  rep(k, K) { cout << ABC[k] << endl; }
}