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
  int N, M;
  cin >> N >> M;

  vector<int> L(M), R(M);
  rep(i, M) cin >> L[i] >> R[i];

  /* min_R - max_L + 1 */
  sort(all(R));
  sort(all(L), greater<int>());
  cout << max(0, R[0] - L[0] + 1) << endl;
}