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
  vector<ll> a(N);
  rep(i, N) cin >> a[i];
  vector<ll> b(N);
  rep(i, N) cin >> b[i];

  ll sumA = 0;
  ll sumB = 0;
  rep(i, N) {
    sumA += a[i];
    sumB += b[i];
  }

  if (sumB < sumA) {
    cout << "No" << endl;
    return 0;
  }

  ll ope = sumB - sumA;
  ll opeA = 0;
  ll opeB = 0;
  rep(i, N) {
    if (a[i] > b[i]) {
      ll diff = a[i] - b[i];
      opeB += diff;
    } else if (a[i] < b[i]) {
      ll diff = b[i] - a[i];
      if (diff % 2 == 0) {
        opeA += diff / 2;
      } else {
        opeA += (diff + 1) / 2;
        opeB++;
      }
    }
  }

  if (opeA > ope || opeB > ope) {
    cout << "No" << endl;
    return 0;
  }

  ll resA = ope - opeA;
  ll resB = ope - opeB;

  if (resA * 2 != resB) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}