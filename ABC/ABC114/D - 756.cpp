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

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1)
    res[n] = 1;
  return res;
}

vector<ll> ind;

int f(int x) {
  int ans = 0;
  rep(i, ind.size()) {
    if (ind[i] >= x)
      ans++;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;

  map<ll, ll> num_ind;
  repp(i, 2, N) {
    map<ll, ll> m = prime_factor(i);
    for (auto iter = m.begin(); iter != m.end(); iter++) {
      ll num = iter->fi;
      ll ind = iter->se;
      num_ind[num] += ind;
    }
  }

  for (auto iter = num_ind.begin(); iter != num_ind.end(); iter++) {
    ll index = iter->se;
    ind.pb(index + 1);
  }

  int M = ind.size();
  int ans = 0;

  ans += f(75);
  ans += f(15) * (f(5) - 1);
  ans += f(25) * (f(3) - 1);
  ans += f(5) * (f(5) - 1) * (f(3) - 2) / 2;
  cout << ans << endl;
}