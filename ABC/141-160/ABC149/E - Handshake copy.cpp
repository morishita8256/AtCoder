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

template <class T>
T find_max(T l, T r, bool f(T)) {
  T c;
  while (r - l > 1) {
    c = (r + l) / 2;
    if (f(c)) {
      l = c;
    } else {
      r = c;
    }
  }
  return l;
}

ll N, M;
vector<ll> A;
ll CNT;


bool f(ll sub) {
  ll cnt = 0;
  rep(i, N) {
    ll res = sub - A[i];
    auto iter = lower_bound(all(A), res);
    ll pos = distance(A.begin(), iter);
    cnt += (N - pos);
  }
  if (cnt >= M) {
    CNT = cnt;
    return true;
  } else {
    return false;
  }
}


int main() {
  cin >> N >> M;
  A = vector<ll>(N);


  rep(i, N) {
    cin >> A[i];
  }
  sort(all(A));


  ll sub = find_max(0LL, (ll)(INF), f);

  auto B = A;
  reverse(all(B));

  vector<ll> sum(N);
  sum[0] = B[0];
  rep(i, N - 1) {
    sum[i + 1] = sum[i] + B[i + 1];
  }

  ll ans = 0;
  rep(i, N) {
    ll res = sub - A[i];
    auto iter = lower_bound(all(A), res);
    ll pos = distance(A.begin(), iter);
    ll cnt = (N - pos);
    if (cnt > 0)
      ans += sum[cnt - 1] + cnt * A[i];
  }
  ans -= sub * (CNT - M);
  cout << ans << endl;
}