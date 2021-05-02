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
  ll N, T;
  cin >> N >> T;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  T /= 2;
  priority_queue<ll, vector<ll>, greater<ll>> Min;
  vector<ll> Mn(N);
  repp(i, 0, N - 2) {
    Min.push(A[i]);
    Mn[i] = Min.top();
  }

  priority_queue<ll> Max;
  vector<ll> Mx(N);
  repr(i, N - 1, 1) {
    Max.push(A[i]);
    Mx[i] = Max.top();
  }

  ll max_prof = 0;
  rep(i, N - 1) {
    chmax(max_prof, Mx[i + 1] - Mn[i]);
  }

  int ans = 0;
  rep(i, N - 1) {
    if (Mx[i + 1] - A[i] == max_prof)
      ans++;
  }
  cout << ans << endl;
}