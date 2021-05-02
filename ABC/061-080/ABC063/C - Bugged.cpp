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
  vector<int> s(N);
  int sum = 0;
  rep(i, N) {
    cin >> s[i];
    sum += s[i];
  }
  sort(all(s));

  if (sum % 10 != 0) {
    cout << sum << endl;
    return 0;
  } else {
    rep(i, N) {
      if (s[i] % 10 != 0) {
        cout << sum - s[i] << endl;
        return 0;
      }
    }
    cout << 0 << endl;
  }
}