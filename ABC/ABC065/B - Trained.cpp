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
  rep(i, N) {
    cin >> a[i];
    a[i]--;
  }

  vector<bool> checked(N, false);
  int ans = 1;
  int now = 0;
  rep(i, N) {
    checked[now] = true;
    int next = a[now];
    if (next == 1) {
      cout << ans << endl;
      return 0;
    }
    if (checked[next]) {
      cout << -1 << endl;
      return 0;
    }
    now = next;
    ans++;
  }
}