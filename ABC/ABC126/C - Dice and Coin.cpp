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
  int N, K;
  cin >> N >> K;

  double p = 0.0;
  repp(i, 1, N) {
    int logK = ceil(log2(1.0 * K / i));
    logK = max(0, logK);
    p += 1 / (1.0 * N * pow(2, logK));
  }
  cout << setprecision(12) << p << endl;
}