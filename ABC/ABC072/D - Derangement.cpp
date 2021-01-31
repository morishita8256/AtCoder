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
  int N;
  cin >> N;
  vector<int> p(N);
  vector<bool> match(N, false);
  rep(i, N) {
    cin >> p[i];
    p[i]--;
    if (i == p[i]) {
      match[i] = true;
    }
  }

  int ans = 0;
  rep(i, N) {
    if (!match[i])
      continue;
    ans++;
    if ((i < N - 1) && match[i + 1]) {
      i++;
    }
  }
  cout << ans << endl;
}