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

  priority_queue<ll, vector<ll>, greater<ll>> plus;
  priority_queue<ll> minus;

  vector<ll> L(N);
  ll L_sum = 0;
  rep(i, N) {
    cin >> L[i];
    L_sum += L[i];
    plus.push(L[i]);
  }

  vector<ll> C(N);
  rep(i, N) cin >> C[i];

  vector<ll> R(N);
  ll R_sum = 0;
  rep(i, N) {
    cin >> R[i];
    R_sum += R[i];
    minus.push(R[i]);
  }

  vector<ll> plus_sum(N + 1);
  plus_sum[0] = L_sum;
  repp(k,0, N-1) {
    plus.push(C[k]);
    L_sum += C[k];
    L_sum -= plus.top();
    plus.pop();
    plus_sum[k + 1] = L_sum;
  }

  vector<ll> minus_sum(N + 1);
  minus_sum[N] = R_sum;
  repr(k, N - 1, 0) {
    minus.push(C[k]);
    R_sum += C[k];
    R_sum -= minus.top();
    minus.pop();
    minus_sum[k] = R_sum;
  }

  ll ans = -LINF;
  rep(i, N + 1) {
    chmax(ans, plus_sum[i] - minus_sum[i]);
  }

  cout << ans << endl;
}