#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// 1からnまででnと互いに素なものの個数
/////////////////////////////////////////
int EulerPhi(int n) {
  if (n == 0)
    return 0;
  int ans = n;
  for (int x = 2; x * x <= n; ++x) {
    if (n % x == 0) {
      ans -= ans / x;
      while (n % x == 0)
        n /= x;
    }
  }
  if (n > 1)
    ans -= ans / n;
  return ans;
}
/////////////////////////////////////////

/*
https://codeforces.com/contest/1295/problem/D
*/
signed main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    int a, m;
    cin >> a >> m;
    int GCD = gcd(a, m);
    m /= GCD;
    int ans = EulerPhi(m);
    cout << ans << endl;
  }
}