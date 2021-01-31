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
  string S;
  cin >> S;

  int N = S.size();

  int diff_1 = 0;
  int diff_2 = 0;

  rep(i, N) {
    if (i % 2 == 0) {
      diff_1 += (S[i] - '0' == 0);
      diff_2 += (S[i] - '0' == 1);
    } else {
      diff_1 += (S[i] - '0' == 1);
      diff_2 += (S[i] - '0' == 0);
    }
  }

  cout << min(diff_1, diff_2) << endl;
}