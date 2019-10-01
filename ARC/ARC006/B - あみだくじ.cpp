#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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
  int N, L;
  cin >> N >> L;
  cin.ignore();
  vector<string> a(L + 1);
  rep(i, L + 1) {
    getline(cin, a[i]);
  }

  int jj = 0;
  rep(j, 2 * N - 1) {
    if (a[L][j] == 'o')
      jj = j;
  }

  int ii = L - 1;
  while (ii >= 0) {
    if (jj > 0 && a[ii][jj - 1] == '-') {
      jj -= 2;
    } else if (jj < 2 * N - 2 && a[ii][jj + 1] == '-') {
      jj += 2;
    }
    ii--;
  }
  jj = jj / 2 + 1;
  cout << jj << endl;
}