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
const int MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;

  vector<int> V(N);
  rep(i, N) cin >> V[i];

  vector<int> C(N);
  rep(i, N) cin >> C[i];

  int ans = 0;
  rep(i, N) { ans += max(0, V[i] - C[i]); }
  cout << ans << endl;
}