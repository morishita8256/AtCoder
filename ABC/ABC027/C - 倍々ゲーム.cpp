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
  ll N;
  cin >> N;

  ll N_cp = N;
  int d = 0;
  while (N_cp) {
    d++;
    N_cp /= 2;
  }

  if (d % 2) {
    int i = 0;
    ll x = 1;
    while (x <= N) {
      if (i % 2 == 0)
        x = x * 2 + 1;
      else
        x = x * 2;
      i++;
    }
    if (i % 2)
      cout << "Aoki" << endl;
    else
      cout << "Takahashi" << endl;
  } else {
    int i = 0;
    ll x = 1;
    while (x <= N) {
      if (i % 2 == 0)
        x = x * 2;
      else
        x = x * 2 + 1;
      i++;
    }
    if (i % 2)
      cout << "Aoki" << endl;
    else
      cout << "Takahashi" << endl;
  }
}