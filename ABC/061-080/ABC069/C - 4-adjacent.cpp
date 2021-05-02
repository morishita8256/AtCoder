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

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  int num_4 = 0;
  int num_2 = 0;
  int num_1 = 0;

  rep(i, N) {
    if (a[i] % 4 == 0)
      num_4++;
    else if (a[i] % 2 == 0)
      num_2++;
    else
      num_1++;
  }

  if (num_2 == 0) {
    if (num_1 <= num_4 + 1) {
      cout << "Yes" << endl;
      return 0;
    }
  } else {
    if (num_1 <= num_4) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}