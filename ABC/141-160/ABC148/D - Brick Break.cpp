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

ll N;
vector<int> a;


bool f(ll trial) {
  int num = 1;
  rep(i, N) {
    if (num == a[i])
      num++;
  }
  num--;
  return (trial <= num);
}

int main() {
  cin >> N;
  a = vector<int>(N);
  rep(i, N) {
    cin >> a[i];
  }

  bool ok = false;
  rep(i, N) {
    if (a[i] == 1)
      ok = true;
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }

  ll res = find_max(0LL, N + 1, f);
  cout << N - res << endl;
}