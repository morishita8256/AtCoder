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

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) {
    cin >> a[i] >> b[i];
  }

  vector<int> imos(1000002);
  rep(i, n) {
    imos[a[i]]++;
    imos[b[i] + 1]--;
  }

  int temp = 0;
  int ans = 0;

  rep(i, 1000001) {
    temp += imos[i];
    chmax(ans, temp);
  }
  cout << ans << endl;
}