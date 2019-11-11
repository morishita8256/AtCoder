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

struct test {
  ll A, B, C;
  test(ll A, ll B, ll C) : A(A), B(B), C(C) {
  }

  bool operator<(const test& another) const {
    return C < another.C;
  };
};


int main() {
  vector<test> X;
  rep(i, 5) {
    X.pb(test(i + 1, 5 - i, (i - 2) * (i - 2)));
  }

  rep(i, 5) {
    cout << X[i].A << ' ' << X[i].B << ' ' << X[i].C << endl;
  }


  sort(all(X));
  cout << endl;
  rep(i, 5) {
    cout << X[i].A << ' ' << X[i].B << ' ' << X[i].C << endl;
  }
}